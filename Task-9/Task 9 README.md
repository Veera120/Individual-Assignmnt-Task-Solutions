# Vector Algebra Library 

This project demonstrates a templated vector algebra 
- Perform operations like addition, scalar multiplication
- Compute dot and cross products
- Normalize vectors

#  Features

Vector Representation :
Vectors are created using a list of elements.
Example:
Vector<double> v1{9.0, 12.0, 31.0};
Vector<double> v2{41.0, 23.0, 16.0};
These represent:
v1 = 9i + 12j + 31k
v2 = 41i + 23j + 16k

 Operations Supported :

- Display: Prints the vector in readable form.
- Addition: 'v1 + v2' → Adds corresponding components.
- Scalar Multiplication: 'v1 * scalar' → Scales each component.
- Dot Product: 'v1.dot(v2)' → Returns scalar result from sum of products.
- Cross Product: 'v1.cross(v2)' → Returns vector (3D only, 'i', 'j', 'k' result).
- Normalization: 'v1.normalize()' → Returns unit vector in same direction.

#  Files

'Task 9 Vector Algebra Library.cpp' Contains 
- Templated class 'Vector<T>' using standard C++.
- All methods (add, scalar multiply, dot/cross product, normalize).
- Error handling for size mismatch or invalid operations.
- Demonstrates usage with two 3D vectors.


#  Sample Output

Vector v1: [ 9 12 31 ]
Vector v2: [ 41 23 16 ]
v1 + v2 = [ 50 35 47 ]
v1 * 2 = [ 18 24 62 ]
v1 . v2 = 1099
v1 x v2 = [ -620 1155 -339 ]
Normalized v1 = [ 0.260272 0.347029 0.896451 ]

# How to Run (For Assessment Purpose)

1. Go to [OnlineGDB](https://www.onlinegdb.com/online_c++_compiler)
2. Type code into the editor
3. Click *Run*