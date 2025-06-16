#include <iostream>
#include <cmath>
using namespace std;
// Function to integrate
double f(double x) {
    return sin(x);  // You can change this to any function
}
// Trapezoidal Rule implementation
double trapezoidal(double a, double b, int n) {
    double h = (b - a) / n;
    double result = f(a) + f(b);
    for (int i = 1; i < n; ++i) {
        result += 2 * f(a + i * h);
    }
    return (h / 2.0) * result;
}
// Simpson's Rule implementation
double simpson(double a, double b, int n) {
    if (n % 2 != 0) {
        cout << "Simpson's Rule needs even number of intervals.\n";
        return 0;
    }
    double h = (b - a) / n;
    double result = f(a) + f(b);

    for (int i = 1; i < n; ++i) {
        if (i % 2 == 0)
            result += 2 * f(a + i * h);
        else
            result += 4 * f(a + i * h);
    }
    return (h / 3.0) * result;
}
// Exact value of ∫sin(x) dx from a to b
double exact_integral(double a, double b) {
    return -cos(b) + cos(a);
}
int main() {
    double a = 0;
    double b = 13;         // Updated upper limit
    int n = 10;            // Number of intervals (even for Simpson)
    double trap = trapezoidal(a, b, n);
    double simp = simpson(a, b, n);
    double exact = exact_integral(a, b);
    cout << "Integrating sin(x) from 0 to 13\n";
    cout << "----------------------------------\n";
    cout << "Trapezoidal Rule Result : " << trap << endl;
    cout << "Simpson's Rule Result   : " << simp << endl;
    cout << "Exact Value             : " << exact << endl;
    cout << "Trapezoidal Error       : " << fabs(trap - exact) << endl;
    cout << "Simpson's Rule Error    : " << fabs(simp - exact) << endl;

    return 0;
}
