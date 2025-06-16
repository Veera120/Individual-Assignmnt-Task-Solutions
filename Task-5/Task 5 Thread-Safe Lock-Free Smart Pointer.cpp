#include <iostream>
#include <atomic>
#include <memory>
#include <thread>
#include <vector>
#include <chrono>

using namespace std;

// Lock-Free Smart Pointer Implementation

template <typename T>
class LockFreeSharedPtr {
private:
    struct ControlBlock {
        std::atomic<int> ref_count;  // Atomic ref counter
        T* ptr;                      // Managed object

        ControlBlock(T* p) : ref_count(1), ptr(p) {}
        ~ControlBlock() {
            delete ptr;
        }
    };

    ControlBlock* control;  // Pointer to control block

public:
    // Constructor
    explicit LockFreeSharedPtr(T* p = nullptr) {
        control = p ? new ControlBlock(p) : nullptr;
    }

    // Copy Constructor
    LockFreeSharedPtr(const LockFreeSharedPtr& other) {
        control = other.control;
        if (control) {
            control->ref_count.fetch_add(1, std::memory_order_relaxed);
        }
    }

    // Assignment Operator
    LockFreeSharedPtr& operator=(const LockFreeSharedPtr& other) {
        if (this != &other) {
            if (other.control) {
                other.control->ref_count.fetch_add(1, std::memory_order_relaxed);
            }
            if (control && control->ref_count.fetch_sub(1, std::memory_order_acq_rel) == 1) {
                delete control;
            }
            control = other.control;
        }
        return *this;
    }

    // Destructor
    ~LockFreeSharedPtr() {
        if (control && control->ref_count.fetch_sub(1, std::memory_order_acq_rel) == 1) {
            delete control;
        }
    }

    // Access methods
    T& operator*() const { return *(control->ptr); }
    T* operator->() const { return control->ptr; }

    // Returns current use count
    int use_count() const {
        return control ? control->ref_count.load(std::memory_order_relaxed) : 0;
    }
};

// Atomic Add Function (Thread-safe value update)

void atomic_add(std::atomic<int>& target, int value) {
    int expected = target.load();
    while (!target.compare_exchange_weak(expected, expected + value,
                                         std::memory_order_relaxed));
}

//  Shared Stress Test Template

template <typename SharedPtrType>
void stress_test_shared_ptr(const std::string& label) {
    const int num_threads = 9;         // Safer on limited environments
    const int iterations = 100000;     // Per thread

    SharedPtrType shared(new std::atomic<int>(0));

    auto start = chrono::high_resolution_clock::now();

    vector<thread> threads;
    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back([shared, iterations]() mutable {
            for (int j = 0; j < iterations; ++j) {
                SharedPtrType local = shared;
                atomic_add(*local, 1); // Thread-safe increment
            }
        });
    }

    for (auto& th : threads) th.join();

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "[" << label << "] Final Value: " << shared->load()
         << ", use_count: " << shared.use_count()
         << ", Time: " << duration.count() << " sec\n";
}

//  Main Function: Run Benchmark

int main() {
    cout << "🔧 Stress Testing with 9 threads × 100K iterations\n\n";

    // Lock-free custom smart pointer
    stress_test_shared_ptr<LockFreeSharedPtr<std::atomic<int>>>("LockFreeSharedPtr");

    // Standard std::shared_ptr
    stress_test_shared_ptr<std::shared_ptr<std::atomic<int>>>("std::shared_ptr");

    return 0;
}
