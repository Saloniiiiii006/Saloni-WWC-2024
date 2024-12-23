#include <iostream>
#include <vector>
using namespace std;

bool PredictTheWinner(vector<int>& nums) {
    int n = nums.size();
    
    // DP table to store the maximum score Player 1 can achieve
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    // Base case: when the subarray has only one element, Player 1 picks that element
    for (int i = 0; i < n; ++i) {
        dp[i][i] = nums[i];
    }
    
    // Fill the DP table for all subarrays of length 2 to n
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            // Player 1 has two choices, take nums[i] or nums[j]
            dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
        }
    }
    
    // If Player 1's score is >= 0, they can win or tie, otherwise Player 2 wins
    return dp[0][n - 1] >= 0;
}

int main() {
    vector<int> nums = {1, 5, 2};
    if (PredictTheWinner(nums)) {
        cout << "Player 1 can win!" << endl;
    } else {
        cout << "Player 1 cannot win!" << endl;
    }
    
    return 0;
}
