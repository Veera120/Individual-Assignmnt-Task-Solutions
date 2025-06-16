# Expression Evaluator in C++

This project implements a parser and evaluator for arithmetic expressions in C++. It supports:
- Parentheses '()'
- Operators: '+', '-', '*', '/'
- Correct operator *precedence* and *associativity*
- Error handling for invalid expressions (e.g., division by zero)

#  File Info
- 'Task 2 Expression Evaluator .cpp' — contains the Expression Evaluator and a test function and full version code.

# Features

- Infix to Postfix conversion using *Shunting Yard Algorithm*  
- Postfix expression evaluation using a *stack*  
- Multiple test cases with distinct results  
- Simple and clean C++ code for beginners


# Sample Expressions & Results

 1 + 2 * 3  = 7    
50 + 10 * 5 =  100  
300 - (25 * 4) =  200 
1000 / (5 + 5) =  100
(7 + 3) * (6 - 2) = 40   
9 * 9 - 8 + 2 = 75  
2 + 3 * (10 - 6) + 5=19   
144 / (3 * 4)` =  12   
# How It Works

1. *Parser*: Converts infix expressions like 3 + 4 * 2 to postfix:3 4 2 * +
2. *Evaluator*: Uses a stack to compute the result of the postfix expression.
3. *Main Function*: Runs a list of test expressions and prints results.

# How to Run (For Assessment Purpose)

1. Go to [OnlineGDB](https://www.onlinegdb.com/online_c++_compiler)
2. Type code into the editor
3. Click *Run*
