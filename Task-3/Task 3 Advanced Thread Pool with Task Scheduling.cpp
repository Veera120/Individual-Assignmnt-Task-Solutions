#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <functional>
#include <future>
#include <mutex>
#include <condition_variable>
#include <chrono>
using namespace std;
// Task with priority
struct Task {
    int id;
    int priority;
    function<void()> func;
    // For priority_queue: higher priority comes first
    bool operator<(const Task& other) const {
        return priority < other.priority;
    }
};
class SimpleThreadPool {
    vector<thread> threads;
    priority_queue<Task> taskQueue;
    mutex mtx;
    condition_variable cv;
    bool stop = false;
public:
    SimpleThreadPool(int numThreads) {
        for (int i = 0; i < numThreads; ++i) {
            threads.emplace_back([this] {
                while (true) {
                    Task task;
                    {
                        unique_lock<mutex> lock(mtx);
                        cv.wait(lock, [this] { return stop || !taskQueue.empty(); });

                        if (stop && taskQueue.empty())
                            return;

                        task = taskQueue.top();
                        taskQueue.pop();
                    }
                    try {
                        task.func();
                        cout << "[Task " << task.id << "] done\n";
                    } catch (exception& e) {
                        cout << "[Task " << task.id << "] error: " << e.what() << "\n";
                    }
                }
            });
        }
    }
    ~SimpleThreadPool() {
        {
            lock_guard<mutex> lock(mtx);
            stop = true;
        }
        cv.notify_all();
        for (auto& t : threads)
            t.join();
    }
    void submit(int id, int priority, function<void()> func) {
        {
            lock_guard<mutex> lock(mtx);
            taskQueue.push(Task{id, priority, func});
        }
        cv.notify_one();
    }
};
//  MAIN FUNCTION
int main() {
    SimpleThreadPool pool(3);
    promise<void> p1, p2;
    shared_future<void> f1 = p1.get_future();
    shared_future<void> f2 = p2.get_future();
    // Task 1
    pool.submit(1, 1, [] {
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "Task 1 running\n";
    });
    // Task 2 (higher priority)
    pool.submit(2, 3, [] {
        cout << "Task 2 running (High Priority)\n";
    });
    // Task 3 (depends on Task 1)
    pool.submit(3, 2, [f1]() mutable {
        f1.wait();
        cout << "Task 3 running after Task 1\n";
    });
    // Task 4 (throws exception)
    pool.submit(4, 4, [] {
        throw runtime_error("Oops! Something went wrong.");
    });
    // Simulate Task 1 completed
    this_thread::sleep_for(chrono::milliseconds(600));
    p1.set_value();
    this_thread::sleep_for(chrono::seconds(2));
    return 0;
}
