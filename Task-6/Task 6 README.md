# Concurrent Multi-Queue Producer-Consumer with Work-Stealing

It implements a multi-Queue producer-consumer system where:

- Each consumer is assigned its own task queue.
- Producers generate tasks and distribute them randomly across multiple queues.
- If a consumer's queue is empty, it steals tasks from other consumers’ queues.
- The system demonstrates efficient load balancing, concurrency, and high throughput.

# Features
- Multiple queues for consumers.
- Producers push tasks into random queues.
- Consumers pull from their own queue, steal from others if idle.
- Uses 'std::mutex' and 'std::condition_variable'.
- Demonstrates load balancing and improved throughput.


# Files
' Task 6 Concurrent Multi-Queue Producer-Consumer with Work-Stealing ', Contains
- Multiple producer threads that generate and distribute tasks to different queues.
- Multiple consumer threads, each with its own queue.
- A work-stealing mechanism where idle consumers try to steal tasks from others.
 
 # Sample Output
 
Task Task 100 executed by thread 200 executed by thread 134696607168192
134696598775488
Task 0 executed by thread 134696446981824
Task 101 executed by thread 134696590382784
Task 201 executed by thread 134696598775488
Task 1 executed by thread 134696446981824

Total execution time: 20 ms

# How to Run (For Assessment Purpose)

1. Go to [OnlineGDB](https://www.onlinegdb.com/online_c++_compiler)
2. Type code into the editor
3. Click *Run*