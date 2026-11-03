#include <iostream>
using namespace std;

// Using Recursion
int fibonacciRec(int n) {
    if (n <= 1)
        return n;

    return fibonacciRec(n - 1) + fibonacciRec(n - 2);
}

// Using Iteration
int fibonacciIter(int n) {
    if (n <= 1)
        return n;

    int a = 0, b = 1, c;

    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

int main() {
    int n;

    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Fibonacci using Recursion: "
         << fibonacciRec(n) << endl;

    cout << "Fibonacci using Iteration: "
         << fibonacciIter(n) << endl;

    return 0;
}