# Numerical Integration using Trapezoidal and Simpson's Rule

This project performs numerical integration using two common methods in C++:
- Trapezoidal Rule
- Simpson's Rule

It calculates the integral of the function sin(x) from 0 to 13 and compares the result with the exact value calculated mathematically.

# Function Being Integrated

The function used is:
sin(x)
Limits of integration:
- Lower limit (a) = 0
- Upper limit (b) = 13

# Methods Used

1. Trapezoidal Rule:
   - Approximates the area under the curve by using trapezoids.
   - Adds the first and last function values once, and the rest twice.

2. Simpson's Rule:
   - Uses parabolas to approximate the curve.
   - Requires an even number of intervals.
   - Adds the first and last values once, the even-indexed values twice, and the odd-indexed values four times.

# Exact Value Calculation

The exact value of the integral of sin(x) is:
- Integral of sin(x) = -cos(x)
- So, the exact value from 0 to 13 is: -cos(13) + cos(0)

This is used to compare and check the accuracy of the numerical results.

# Files

'Task 8 Numerical Integration.cpp' Contains:
- Function definition of sin(x)
- Trapezoidal method implementation
- Simpson’s method implementation
- Exact value calculation

## Sample Output

Integrating sin(x) from 0 to 13
Trapezoidal Rule Result : 0.0791361
Simpson's Rule Result   : 0.0943806
Exact Value             : 0.0925532
Trapezoidal Error       : 0.0134171
Simpson's Rule Error    : 0.00182738


# Accuracy Comparison

Simpson’s Rule is more accurate than the Trapezoidal Rule, especially for smooth functions like sin(x), even with fewer intervals.

# How to Run (For Assessment Purpose)

1. Go to [OnlineGDB](https://www.onlinegdb.com/online_c++_compiler)
2. Type code into the editor
3. Click *Run*