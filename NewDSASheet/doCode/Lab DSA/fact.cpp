#include <iostream>

unsigned long long factorial(unsigned int n, unsigned long long result = 1) {
    if (n == 0) {
        return result;
    }
    return factorial(n - 1, n * result);
}

int main() {
    unsigned int number;
    std::cout << "Enter a positive integer: ";
    std::cin >> number;
    std::cout << "Factorial of " << number << " is " << factorial(number) << std::endl;
    return 0;
}