#include <iostream>
using namespace std;

int power(int a, int n) {
    if (n == 0)
        return 1;

    return a * power(a, n - 1);
}

int main() {
    int a, n;

    cout << "Enter base: ";
    cin >> a;

    cout << "Enter power: ";
    cin >> n;

    cout << "Result = " << power(a, n);

    return 0;
}