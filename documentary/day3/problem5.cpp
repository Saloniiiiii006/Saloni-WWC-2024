#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MOD = 1e9 + 7;

int minNonZeroProduct(int p) {
    // The maximum number in nums is (2^p - 1), i.e., all p bits set to 1
    long long maxNum = (1LL << p) - 1;
    
    // The minimal non-zero product is when the largest number is paired with
    // the second largest number in a manner that minimizes the product
    // after performing the bit-swap operation. The result would be
    // (2^p - 1) * (2^p - 2) raised to the power (2^(p-1) - 1), modulo 1e9 + 7.
    
    // First, compute (maxNum * (maxNum - 1)) % MOD
    long long product = maxNum * (maxNum - 1) % MOD;
    
    // We now need to compute the power (product ^ (2^(p-1) - 1)) % MOD
    long long power = (1LL << (p - 1)) - 1;  // This is 2^(p-1) - 1
    
    // Use modular exponentiation to calculate product^power % MOD
    long long result = 1;
    while (power > 0) {
        if (power % 2 == 1) {
            result = result * product % MOD;
        }
        product = product * product % MOD;
        power /= 2;
    }
    
    return result;
}

int main() {
    int p;
    cout << "Enter the value of p: ";
    cin >> p;
    
    int result = minNonZeroProduct(p);
    cout << "The minimum non-zero product is: " << result << endl;
    
    return 0;
}
