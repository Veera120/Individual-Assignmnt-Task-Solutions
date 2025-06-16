#include <iostream>
#include <stack>
#include <sstream>
#include <map>
#include <cctype>
#include <vector>
#include <stdexcept>
using namespace std;
// Operator precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}
// Apply operation on two operands
double applyOp(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) throw runtime_error("Division by zero!");
            return a / b;
    }
    return 0;
}
// Convert infix to postfix using Shunting Yard algorithm
vector<string> infixToPostfix(const string& expr) {
    vector<string> output;
    stack<char> ops;
    for (size_t i = 0; i < expr.size(); ++i) {
        if (isspace(expr[i])) continue;

        if (isdigit(expr[i])) {
            string num;
            while (i < expr.size() && (isdigit(expr[i]) || expr[i] == '.')) {
                num += expr[i++];
            }
            output.push_back(num);
            --i;
        }
        else if (expr[i] == '(') {
            ops.push('(');
        }
        else if (expr[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                output.push_back(string(1, ops.top()));
                ops.pop();
            }
            ops.pop(); // remove '('
        }
        else if (string("+-*/").find(expr[i]) != string::npos) {
            while (!ops.empty() && precedence(ops.top()) >= precedence(expr[i])) {
                output.push_back(string(1, ops.top()));
                ops.pop();
            }
            ops.push(expr[i]);
        }
    }
    while (!ops.empty()) {
        output.push_back(string(1, ops.top()));
        ops.pop();
    }
    return output;
}
// Evaluate postfix expression
double evaluatePostfix(const vector<string>& tokens) {
    stack<double> st;
    for (const auto& token : tokens) {
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-')) {
            st.push(stod(token));
        } else {
            double b = st.top(); st.pop();
            double a = st.top(); st.pop();
            st.push(applyOp(a, b, token[0]));
        }
    }
    return st.top();
}
// Main expression evaluator
double evaluateExpression(const string& expr) {
    auto postfix = infixToPostfix(expr);
    return evaluatePostfix(postfix);
}
// Test Cases
int main() {
    vector<string> test_cases = {
        "1 + 2 * 3",                  
        "50 + 10 * 5",                
        "300 - (25 * 4)",            
        "1000 / (5 + 5)",            
        "(7 + 3) * (6 - 2)",         
        "9 * 9 - 8 + 2",              
        "2 + 3 * (10 - 6) + 5",      
        "144 / (3 * 4)"         
    };
    for (const auto& expr : test_cases) {
        try {
            cout << "Expression: " << expr << "\nResult: " << evaluateExpression(expr) << "\n\n";
        } catch (exception& e) {
            cout << "Error in expression: " << expr << " - " << e.what() << "\n\n";
        }
    }
    return 0;
}
