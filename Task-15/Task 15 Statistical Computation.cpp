#include <iostream>
#include <vector>
#include <algorithm>  // for sort
#include <numeric>    // for accumulate
#include <cmath>      // for sqrt
using namespace std;
//  mean
double computeMean(const vector<double>& data) {
    double sum = accumulate(data.begin(), data.end(), 0.0);
    return sum / data.size();
}
//  median
double computeMedian(vector<double> data) {
    size_t n = data.size();
    sort(data.begin(), data.end());
    if (n % 2 == 0)
        return (data[n / 2 - 1] + data[n / 2]) / 2;
    else
        return data[n / 2];
}
// variance
double computeVariance(const vector<double>& data, double mean) {
    double sumSquaredDiffs = 0.0;
    for (auto x : data)
        sumSquaredDiffs += (x - mean) * (x - mean);
    return sumSquaredDiffs / data.size(); // population variance
}
// standard deviation
double computeStdDev(double variance) {
    return sqrt(variance);
}
int main() {
    vector<double> values = {19.8, 48, 30.2, 25.4, 15.7};
    double mean = computeMean(values);
    double median = computeMedian(values);
    double variance = computeVariance(values, mean);
    double stddev = computeStdDev(variance);
    cout << "Input values: ";
    for (auto v : values) cout << v << " ";
    cout << "\n";
    cout << "Mean: " << mean << "\n";
    cout << "Median: " << median << "\n";
    cout << "Variance: " << variance << "\n";
    cout << "Standard Deviation: " << stddev << "\n";
    return 0;
}
