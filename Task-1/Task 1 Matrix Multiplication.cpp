#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;
// Matrix Class Template
template<typename T>
class Matrix {
private:
    vector<vector<T>> data;
    int rows, cols;
public:
    // Constructor to create matrix filled with zeros
    Matrix(int r, int c) : rows(r), cols(c) {
        data.resize(rows, vector<T>(cols, 0));
    }
    // Element access using (i, j)
    T& operator()(int i, int j) {
        return data[i][j];
    }
    T operator()(int i, int j) const {
        return data[i][j];
    }
    // Getter functions for rows and cols
    int getRows() const { return rows; }
    int getCols() const { return cols; }
    // Matrix addition
    Matrix operator+(const Matrix& other) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result(i, j) = data[i][j] + other(i, j);
        return result;
    }
    // Matrix subtraction
    Matrix operator-(const Matrix& other) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result(i, j) = data[i][j] - other(i, j);
        return result;
    }
    // Matrix multiplication
    Matrix operator*(const Matrix& other) const {
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < other.cols; ++j)
                for (int k = 0; k < cols; ++k)
                    result(i, j) += data[i][k] * other(k, j);
        return result;
    }
    // Print matrix
    friend ostream& operator<<(ostream& os, const Matrix& mat) {
        for (int i = 0; i < mat.rows; ++i) {
            for (int j = 0; j < mat.cols; ++j)
                os << mat(i, j) << " ";
            os << "\n";
        }
        return os;
    }
};
// Function to Fill Matrix
template<typename T>
void fillMatrix(Matrix<T>& mat, initializer_list<T> values) {
    int index = 0;
    for (int i = 0; i < mat.getRows(); ++i) {
        for (int j = 0; j < mat.getCols(); ++j) {
            mat(i, j) = *(values.begin() + index);
            index++;
        }
    }
}
// Main Function 
int main() {
    Matrix<int> A(2, 2), B(2, 2);
    // matrix
    fillMatrix(A, {9, 6, 3, 4});  
    fillMatrix(B, {2, 4, 7, 8});  
    // results
    cout << "Matrix A:\n" << A;
    cout << "Matrix B:\n" << B;
    cout << "\nA + B =\n" << (A + B);
    cout << "\nA - B =\n" << (A - B);
    cout << "\nA * B =\n" << (A * B);
    return 0;
}
