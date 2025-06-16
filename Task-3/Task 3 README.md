#  Thread Pool 

- Running tasks in *multiple threads*
- Executing tasks based on *priority*
- Waiting for other tasks (using *dependencies*)
- *Catching errors* if a task fails


# What is a Thread Pool?

A *thread pool* is a group of threads that are always ready to do work. Instead of creating a new thread for every task (which is slow), we reuse threads from the pool.

This helps in:
- Saving system resources
- Running tasks faster
- Managing multiple tasks easily


# Features in This Code

- Run tasks in parallel  
- Assign priority to each task (higher runs first)  
- Some tasks can wait for others to finish (dependency)  
- Handles exceptions with 'try-catch'

 # How to Run (For Assessment Purpose)

1. Go to [OnlineGDB](https://www.onlinegdb.com/online_c++_compiler)
2. Type code into the editor
3. Click *Run*

# Example Output

```txt
Task 2 running (High Priority)
Task 1 running
[Task 2] done
[Task 1] done
Task 3 running after Task 1
[Task 3] done
[Task 4] error: Oops! Something went wrong.
