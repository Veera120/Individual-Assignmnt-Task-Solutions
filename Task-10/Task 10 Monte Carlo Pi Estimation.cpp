#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
// Function to estimate Pi using Monte Carlo method
double estimatePi(int totalPoints) {
    int insideCircle = 0;
    for (int i = 0; i < totalPoints; ++i) {
        double x = static_cast<double>(rand())/RAND_MAX;
        double y = static_cast<double>(rand())/RAND_MAX;
        if ((x * x + y * y) <= 1.0) {
            insideCircle++;
        }
    }
    return 4.0 * insideCircle / totalPoints;
}
int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generator
    // Custom sample sizes
    int samples[] = {19, 245, 5487, 36985, 741258, 2589631};
    cout << "Monte Carlo Estimation of Pi:\n";
    for (int i = 0; i < 6; ++i) {
        int n = samples[i];
        double piEstimate = estimatePi(n);
        cout << "Samples: " << n << " -> Estimated Pi: " << piEstimate << endl;
    }
    return 0;
}
