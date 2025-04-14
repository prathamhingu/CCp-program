/*
   Programmer : Pratham Hingu
   Aim        : Compare recursive and iterative approaches for calculating the sum of an array, along with time taken by each
   Date       : 24 February, 2025
*/

#include <iostream>
#include <vector>
#include <chrono>  // For time measurement

using namespace std;
using namespace chrono;

// Iterative function to compute sum of array elements
int iterativeSum(const vector<int>& arr)
{
    int sum = 0;
    for (int num : arr)
        sum += num;
    return sum;
}

// Recursive function to compute sum of array elements
int recursiveSum(const vector<int>& arr, int n)
{
    if (n == 0)
        return 0;
    return arr[n - 1] + recursiveSum(arr, n - 1);
}

int main()
{
    int n;

    // Taking user input for array size
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);  // Dynamic array allocation using vector

    // Taking user input for array elements
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Measuring time for iterative sum
    auto start_iter = high_resolution_clock::now();
    int sum_iterative = iterativeSum(arr);
    auto end_iter = high_resolution_clock::now();
    auto duration_iter = duration_cast<nanoseconds>(end_iter - start_iter);

    // Measuring time for recursive sum
    auto start_rec = high_resolution_clock::now();
    int sum_recursive = recursiveSum(arr, n);
    auto end_rec = high_resolution_clock::now();
    auto duration_rec = duration_cast<nanoseconds>(end_rec - start_rec);

    // Displaying results
    cout << "\n--- Results ---" << endl;
    cout << "Iterative Sum: " << sum_iterative << endl;
    cout << "Time taken (Iterative): " << duration_iter.count() << " ns" << endl;

    cout << "Recursive Sum: " << sum_recursive << endl;
    cout << "Time taken (Recursive): " << duration_rec.count() << " ns" << endl;

    cout << "\nPratham Hingu :: 24CE039" << endl;

    cout << endl;

    return 0;
}

