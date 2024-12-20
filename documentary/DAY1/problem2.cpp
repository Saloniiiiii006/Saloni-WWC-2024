#include <iostream>
#include <cmath>  // For sqrt function
using namespace std;

bool isPrime(int n) {
    // Edge cases
    if (n <= 1) return false;  // Numbers less than or equal to 1 are not prime
    if (n == 2) return true;   // 2 is prime
    if (n % 2 == 0) return false;  // Other even numbers are not prime

    // Check divisibility from 3 to sqrt(n) with a step of 2 (odd numbers only)
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            return false;  // If n is divisible by any number in this range, it's not prime
        }
    }

    return true;  // If no divisors were found, n is prime
}

int main() {
    int number;
    
    cout << "Enter a number: ";
    cin >> number;
    
    if (isPrime(number)) {
        cout << number << " is a prime number." << endl;
    } else {
        cout << number << " is not a prime number." << endl;
    }

    return 0;
}
