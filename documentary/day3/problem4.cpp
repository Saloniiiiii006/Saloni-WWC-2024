#include <iostream>
using namespace std;

int findWinner(int n, int k) {
    int result = 0;  // Base case: if there's only one person, they are the winner
    
    // Iterate from 2 to n to calculate the position of the winner
    for (int i = 2; i <= n; ++i) {
        result = (result + k) % i;
    }
    
    // The result is 0-indexed, so we return the 1-indexed winner
    return result + 1;
}

int main() {
    int n, k;
    cout << "Enter the number of friends (n): ";
    cin >> n;
    cout << "Enter the step size (k): ";
    cin >> k;
    
    int winner = findWinner(n, k);
    cout << "The winner is friend number " << winner << endl;
    
    return 0;
}
