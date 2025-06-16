
#  Polynomial Class and Root Finding

This project demonstrates how to work with polynomials in C++:
- Perform arithmetic operations (add, subtract, multiply)
- Evaluate polynomial at any value of 'x'
- Find roots using Newton-Raphson method


# Features

Polynomial Representation :
Polynomials are created using a list of coefficients (from lowest to highest degree).
Polynomial p({8, 4, -3, 9})

Represents: p(x) = 9x³ - 3x² + 4x + 8

 Operations Supported :

- Display: Prints the polynomial in readable form.
- Evaluate: Calculates value of 'p(x)' at any 'x'.
- Add / Subtract / Multiply: Combines two polynomials.
- Root Finding: Uses Newton-Raphson to find approximate root near a starting point.

# Files

' Task 7 Polynomial Class and Root Finding.cpp ' Contains
- Implements the Polynomial class
- Supports arithmetic and root finding
- example usage and expected output

# Sample Output

Polynomial p(x): 9x^3-3x^2+4x+8
p(2) = 76
Root found near -1: -1.14355

Polynomial q(x): 1x+1
p(x) + q(x) = 9x^3-3x^2+5x+9
p(x) - q(x) = 9x^3-3x^2+3x+7
p(x) * q(x) = 9x^4+6x^3-7x^2+4x+8
 
 
# How to Run (For Assessment Purpose)

1. Go to [OnlineGDB](https://www.onlinegdb.com/online_c++_compiler)
2. Type code into the editor
3. Click *Run*