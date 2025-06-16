#include <iostream>
#include <vector>
#include <algorithm>
#include <future>
#include <chrono>
using namespace std;
// Merge function for two sorted halves
template<typename T>
void merge(vector<T>& arr, int left, int mid, int right) {
    vector<T> temp;
    int i = left, j = mid;
    while (i < mid && j < right) {
        if (arr[i] < arr[j]) temp.push_back(arr[i++]);
        else temp.push_back(arr[j++]);
    }
    while (i < mid) temp.push_back(arr[i++]);
    while (j < right) temp.push_back(arr[j++]);
    // Copy to original array
    for (int k = 0; k < temp.size(); ++k)
        arr[left + k] = temp[k];
}
// Sequential merge sort
template<typename T>
void sequential_merge_sort(vector<T>& arr, int left, int right) {
    if (right - left <= 1) return;
    int mid = (left + right) / 2;
    sequential_merge_sort(arr, left, mid);
    sequential_merge_sort(arr, mid, right);
    merge(arr, left, mid, right);
}
// Concurrent merge sort
template<typename T>
void concurrent_merge_sort(vector<T>& arr, int left, int right, int threshold = 10000) {
    if (right - left <= 1) return;

    if (right - left < threshold) {
        sequential_merge_sort(arr, left, right);
        return;
    }
    int mid = (left + right) / 2;
    // Launch left half in a new thread
    auto future = async(launch::async, [&]() {
        concurrent_merge_sort(arr, left, mid, threshold);
    });
    // Process right half in current thread
    concurrent_merge_sort(arr, mid, right, threshold);
    // Wait for left to finish
    future.get();
    merge(arr, left, mid, right);
}
// Benchmark helper
template<typename Func>
long long measure(Func f) {
    auto start = chrono::high_resolution_clock::now();
    f();
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}
// Main
int main() {
    const int N = 100000;
    vector<int> data1(N), data2(N);
    for (int i = 0; i < N; ++i) {
        data1[i] = rand();
    }
    data2 = data1;
    cout << "Sorting " << N << " integers...\n";
    long long t1 = measure([&]() {
        sequential_merge_sort(data1, 0, data1.size());
    });
    long long t2 = measure([&]() {
        concurrent_merge_sort(data2, 0, data2.size());
    });
    cout << "Sequential Merge Sort Time: " << t1 << " ms\n";
    cout << "Concurrent Merge Sort Time: " << t2 << " ms\n";
    return 0;
}
