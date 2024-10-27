#include<iostream>
using namespace std;
int fibonaccirecursive(int n) {
    if (n <= 1)
        return n;
    return fibonaccirecursive(n - 1) + fibonaccirecursive(n - 2);
}
int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    // n = 10;
    cout << "Fibonacci of " << n << " is: " << fibonaccirecursive(n) << endl;
    return 0;
}