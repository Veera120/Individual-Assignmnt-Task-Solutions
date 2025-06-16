#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
using namespace std;
// Templated Vector class
template<typename T>
class Vector {
private:
    vector<T> data;
public:
    Vector(initializer_list<T> init) : data(init) {}
    size_t size() const { return data.size(); }
    T& operator[](size_t i) { return data[i]; }
    const T& operator[](size_t i) const { return data[i]; }
    // Vector addition
    Vector<T> operator+(const Vector<T>& other) const {
        if (size() != other.size()) throw invalid_argument("Size mismatch");
        Vector<T> result = *this;
        for (size_t i = 0; i < size(); ++i)
            result[i] += other[i];
        return result;
    }
    // Scalar multiplication
    Vector<T> operator*(T scalar) const {
        Vector<T> result = *this;
        for (auto& val : result.data)
            val *= scalar;
        return result;
    }
    // Dot product
    T dot(const Vector<T>& other) const {
        if (size() != other.size()) throw invalid_argument("Size mismatch");
        T sum = 0;
        for (size_t i = 0; i < size(); ++i)
            sum += data[i] * other[i];
        return sum;
    }
    // Cross product (3D only)
    Vector<T> cross(const Vector<T>& other) const {
        if (size() != 3 || other.size() != 3)
            throw invalid_argument("Cross product only for 3D");
        return {
            data[1]*other[2] - data[2]*other[1],
            data[2]*other[0] - data[0]*other[2],
            data[0]*other[1] - data[1]*other[0]
        };
    }
    // Normalize
    Vector<T> normalize() const {
        T len = 0;
        for (const auto& val : data)
            len += val * val;
        len = sqrt(len);
        if (len == 0) throw runtime_error("Zero vector");
        return (*this) * (1.0 / len);
    }
    void print() const {
        cout << "[ ";
        for (const auto& val : data)
            cout << val << " ";
        cout << "]\n";
    }
};
// Main function
int main() {
    Vector<double> v1{9.0, 12.0, 31.0};   // Changed vector 1
    Vector<double> v2{41.0, 23.0, 16.0};  // Changed vector 2
    cout << "Vector v1: "; v1.print();
    cout << "Vector v2: "; v2.print();
    auto v3 = v1 + v2;
    cout << "v1 + v2 = "; v3.print();
    auto v4 = v1 * 2.0;
    cout << "v1 * 2 = "; v4.print();
    double dp = v1.dot(v2);
    cout << "v1 . v2 = " << dp << "\n";
    auto cp = v1.cross(v2);
    cout << "v1 x v2 = "; cp.print();
    auto vn = v1.normalize();
    cout << "Normalized v1 = "; vn.print();
    return 0;
}
