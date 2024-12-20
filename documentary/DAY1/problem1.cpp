#include <iostream>
using namespace std;

int main() {
    int N, sum = 0;
    
    // Input the value of N
    cout << "Enter a number N: ";
    cin >> N;
    
    // Loop to calculate the sum
    for (int i = 1; i <= N; ++i) {
        sum += i;
    }
    
    // Output the sum
    cout << "Sum of natural numbers up to " << N << " is: " << sum << endl;
    
    return 0;
}

