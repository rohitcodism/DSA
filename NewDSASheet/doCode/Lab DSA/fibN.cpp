#include <iostream>

int fibonacci(int n, int a = 0, int b = 1) {
    if (n == 0)
        return a;
    if (n == 1)
        return b;
    return fibonacci(n - 1, b, a + b);
}

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;
    std::cout << "The " << n << "th Fibonacci number is: " << fibonacci(n) << std::endl;
    return 0;
}