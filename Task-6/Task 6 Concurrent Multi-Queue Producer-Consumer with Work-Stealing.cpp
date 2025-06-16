#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <random>
#include <chrono>
using namespace std;
constexpr int NUM_QUEUES = 4;           // Number of queues / consumer threads
constexpr int NUM_PRODUCERS = 3;
constexpr int TASKS_PER_PRODUCER = 2;
struct Task {
    int id;
    Task(int i) : id(i) {}
    void execute() {
        cout << "Task " << id << " executed by thread " << this_thread::get_id() << endl;
        this_thread::sleep_for(chrono::milliseconds(10));
    }
};
// Shared queues
vector<queue<Task>> task_queues(NUM_QUEUES);
vector<mutex> queue_mutexes(NUM_QUEUES);
vector<condition_variable> queue_conds(NUM_QUEUES);
atomic<bool> done = false;
// Producer: pushes tasks to random queues
void producer(int producer_id) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, NUM_QUEUES - 1);

    for (int i = 0; i < TASKS_PER_PRODUCER; ++i) {
        int queue_id = dist(gen);
        Task task(producer_id * 100 + i); // Unique task ID
        {
            lock_guard<mutex> lock(queue_mutexes[queue_id]);
            task_queues[queue_id].push(task);
        }
        queue_conds[queue_id].notify_one();
        this_thread::sleep_for(chrono::milliseconds(5));
    }
}
// Consumer: pops from its own queue, steals from others if empty
void consumer(int queue_id) {
    while (!done) {
        Task task(1);
        bool has_task = false;

        {
            unique_lock<mutex> lock(queue_mutexes[queue_id]);
            queue_conds[queue_id].wait_for(lock, chrono::milliseconds(10), [&] {
                return !task_queues[queue_id].empty() || done;
            });

            if (!task_queues[queue_id].empty()) {
                task = task_queues[queue_id].front();
                task_queues[queue_id].pop();
                has_task = true;
            }
        }
        if (!has_task) {
            // Try stealing
            for (int i = 0; i < NUM_QUEUES; ++i) {
                if (i == queue_id) continue;
                lock_guard<mutex> lock(queue_mutexes[i]);
                if (!task_queues[i].empty()) {
                    task = task_queues[i].front();
                    task_queues[i].pop();
                    has_task = true;
                    break;
                }
            }
        }
        if (has_task) {
            task.execute();
        }
    }
    // Final drain of remaining tasks
    while (true) {
        Task task(1);
        bool has_task = false;
        {
            lock_guard<mutex> lock(queue_mutexes[queue_id]);
            if (!task_queues[queue_id].empty()) {
                task = task_queues[queue_id].front();
                task_queues[queue_id].pop();
                has_task = true;
            }
        }
        if (!has_task) break;
        task.execute();
    }
}
// Main Function
int main() {
    auto start = chrono::high_resolution_clock::now();
    vector<thread> producers;
    vector<thread> consumers;
    for (int i = 0; i < NUM_PRODUCERS; ++i)
        producers.emplace_back(producer, i);
    for (int i = 0; i < NUM_QUEUES; ++i)
        consumers.emplace_back(consumer, i);
    for (auto& p : producers)
        p.join();
    done = true;
    for (int i = 0; i < NUM_QUEUES; ++i)
        queue_conds[i].notify_all();
    for (auto& c : consumers)
        c.join();
    auto end = chrono::high_resolution_clock::now();
    cout << "\nTotal execution time: "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    return 0;
}
