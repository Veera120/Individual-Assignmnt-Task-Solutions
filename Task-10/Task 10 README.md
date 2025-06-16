
# Monte Carlo Pi Estimation

This project demonstrates how to estimate the value of π using the Monte Carlo method 

# Features
- Randomly generate points inside a unit square (x, y from 0 to 1)
- Count how many fall inside a unit quarter-circle (x² + y² ≤ 1)
- Use the ratio of points inside the circle to total points
- Estimate π using: π ≈ 4 × (inside_circle / total_points)

# Sample Sizes

The program uses the following number of random points to demonstrate accuracy:
int samples[] = {19, 245, 5487, 36985, 741258, 2589631}
As sample size increases, the estimate becomes more accurate.

# Files

'Task 10 Monte Carlo Pi Estimation.cpp' contains:
- Monte Carlo π estimation logic
- Loop through sample sizes
- Prints estimated value of Pi

# Sample Output

Monte Carlo Estimation of Pi:
Samples: 19 -> Estimated Pi: 3.15789
Samples: 245 -> Estimated Pi: 3.10816
Samples: 5487 -> Estimated Pi: 3.13063
Samples: 36985 -> Estimated Pi: 3.14025
Samples: 741258 -> Estimated Pi: 3.14193
Samples: 2589631 -> Estimated Pi: 3.14149

# How to Run (For Assessment Purpose)

1. Go to [OnlineGDB](https://www.onlinegdb.com/online_c++_compiler)
2. Type code into the editor
3. Click *Run*

