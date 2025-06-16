# Generic Concurrent Merge Sort in C++

This project demonstrates a generic and concurrent merge sort using C++ features like:
- Templates (for generic data types)
- Lambdas
- std::async for parallel execution
- Adaptive thresholding to switch between sequential and parallel sort

# Features

- Works for any data type ('int', 'float', 'string')
- Uses multi-threading for large arrays
- Automatically switches to single-thread for small arrays
- Benchmarks included (sequential vs concurrent)

# Files

- 'Task 4 Efficient Generic Concurrent Merge Sort .cpp' – Full implementation with sorting and benchmarking

# Simple Output

Sorting 100000 integers...
Sequential Merge Sort Time: 124 ms
Concurrent Merge Sort Time: 110 ms

# How to Run (For Assessment Purpose)

1. Go to [OnlineGDB](https://www.onlinegdb.com/online_c++_compiler)
2. Type code into the editor
3. Click *Run*

