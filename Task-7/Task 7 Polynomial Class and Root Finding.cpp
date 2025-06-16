#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// Simple Polynomial class
class Polynomial {
private:
    vector<double> coeffs; // coeffs[i] means coefficient of x^i
public:
    // Constructor
    Polynomial(const vector<double>& c) {
        coeffs = c;
    }
    // Display the polynomial
    void display() {
        for (int i = coeffs.size() - 1; i >= 0; i--) {
            if (coeffs[i] != 0) {
                if (i != coeffs.size() - 1 && coeffs[i] > 0)
                    cout << "+";
                if (i == 0)
                    cout << coeffs[i];
                else if (i == 1)
                    cout << coeffs[i] << "x";
                else
                    cout << coeffs[i] << "x^" << i;
                cout << " ";
            }
        }
        cout << endl;
    }
    // Evaluate polynomial at x
    double evaluate(double x) {
        double result = 0;
        for (int i = 0; i < coeffs.size(); i++) {
            result += coeffs[i] * pow(x, i);
        }
        return result;
    }
    // Derivative of the polynomial
    Polynomial derivative() {
        vector<double> deriv;
        for (int i = 1; i < coeffs.size(); i++) {
            deriv.push_back(i * coeffs[i]);
        }
        return Polynomial(deriv);
    }
    // Add two polynomials
    Polynomial add(const Polynomial& other) {
        int maxSize = max(coeffs.size(), other.coeffs.size());
        vector<double> result(maxSize, 0);
        for (int i = 0; i < coeffs.size(); i++)
            result[i] += coeffs[i];
        for (int i = 0; i < other.coeffs.size(); i++)
            result[i] += other.coeffs[i];
        return Polynomial(result);
    }
    // Subtract two polynomials
    Polynomial subtract(const Polynomial& other) {
        int maxSize = max(coeffs.size(), other.coeffs.size());
        vector<double> result(maxSize, 0);
        for (int i = 0; i < coeffs.size(); i++)
            result[i] += coeffs[i];
        for (int i = 0; i < other.coeffs.size(); i++)
            result[i] -= other.coeffs[i];
        return Polynomial(result);
    }
    // Multiply two polynomials
    Polynomial multiply(const Polynomial& other) {
        int sizeA = coeffs.size();
        int sizeB = other.coeffs.size();
        vector<double> result(sizeA + sizeB - 1, 0);
        for (int i = 0; i < sizeA; i++) {
            for (int j = 0; j < sizeB; j++) {
                result[i + j] += coeffs[i] * other.coeffs[j];
            }
        }
        return Polynomial(result);
    }
    // Newton-Raphson to find root near x0
    double findRoot(double x0, int maxIter = 20, double tol = 1e-6) {
        Polynomial deriv = this->derivative();
        for (int i = 0; i < maxIter; i++) {
            double fx = evaluate(x0);
            double fpx = deriv.evaluate(x0);
            if (fabs(fpx) < 1e-10) break; // Avoid divide by zero
            double x1 = x0 - fx / fpx;
            if (fabs(x1 - x0) < tol)
                return x1;
            x0 = x1;
        }
        return x0;
    }
};
//  MAIN FUNCTION 
int main() {
    // Create polynomial: p(x) = x^3  x^2  x  
    Polynomial p({8, 4, -3, 9});  // coeffs: constant, x, x^2, x^3
    cout << "Polynomial p(x): ";
    p.display();
    // Evaluate at x = 2
    cout << "p(2) = " << p.evaluate(2) << endl;
    // Find root near x = -1
    double root = p.findRoot(-1);
    cout << "Root found near -1: " << root << endl;
    // Another polynomial: q(x) = x + 1
    Polynomial q({1, 1});
    cout << "\nPolynomial q(x): ";
    q.display();
    // Addition
    Polynomial sum = p.add(q);
    cout << "p(x) + q(x) = ";
    sum.display();
    // Subtraction
    Polynomial diff = p.subtract(q);
    cout << "p(x) - q(x) = ";
    diff.display();
    // Multiplication
    Polynomial prod = p.multiply(q);
    cout << "p(x) * q(x) = ";
    prod.display();
    return 0;
}
