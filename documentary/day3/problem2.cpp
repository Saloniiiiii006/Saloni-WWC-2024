#include <iostream>
#include <vector>
using namespace std;

int findRemainingNumber(int n) {
    vector<int> arr;
    
    // Step 1: Initialize the array with values 1 to n
    for (int i = 1; i <= n; ++i) {
        arr.push_back(i);
    }

    bool leftToRight = true;  // We start with left-to-right

    // Keep repeating the steps until we have only one number left
    while (arr.size() > 1) {
        vector<int> newArr;

        if (leftToRight) {
            // Left to right: Remove every other element
            for (int i = 0; i < arr.size(); i += 2) {
                newArr.push_back(arr[i]);
            }
        } else {
            // Right to left: Remove every other element
            for (int i = arr.size() - 1; i >= 0; i -= 2) {
                newArr.push_back(arr[i]);
            }
            // Since we are moving right to left, we reverse the new array
            reverse(newArr.begin(), newArr.end());
        }

        // Update arr with the new reduced list
        arr = newArr;

        // Alternate the direction
        leftToRight = !leftToRight;
    }

    // The last remaining number
    return arr[0];
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int result = findRemainingNumber(n);
    cout << "The remaining number is: " << result << endl;

    return 0;
}
