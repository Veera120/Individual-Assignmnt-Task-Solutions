# Thread-safe Lock-Free Smart Pointer in C++

This project implements a thread-safe, lock-free smart pointer using atomic reference counting in C++. It compares the performance and correctness of this custom smart pointer with the standard 'std::shared_ptr'.

# Features

-  Lock-free, thread-safe smart pointer ('LockFreeSharedPtr')
-  Atomic reference counting using 'std::atomic<int>'
-  No mutexes or locks used
-  Multi-threaded stress testing with 8 threads × 100K iterations
-  Benchmarked against 'std::shared_ptr'

# Files

 'Task 5 Thread-Safe Lock-Free Smart Pointer.cpp' Contains implementation, stress test, and benchmarking 

# Sample Output

 Stress Testing with 9 threads × 100K iterations

[LockFreeSharedPtr] Final Value: 900000, use_count: 1, Time: 0.142345 sec
[std::shared_ptr] Final Value: 900000, use_count: 1, Time: 0.299493 sec

# How to Run (For Assessment Purpose)

1. Go to [OnlineGDB](https://www.onlinegdb.com/online_c++_compiler)
2. Type code into the editor
3. Click *Run*