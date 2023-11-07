#include <iostream>
using namespace std;
int fibRecursive(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

int fibIterative(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    int a = 1;
    int b = 1;
    for (int i = 2; i <= n; i++) {
        int c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "n'th Fibonacci number by Recursive method: " << fibRecursive(n) << std::endl;
    cout << "n'th Fibonacci number by Iterative method: " << fibIterative(n) << std::endl;
    return 0;
}

