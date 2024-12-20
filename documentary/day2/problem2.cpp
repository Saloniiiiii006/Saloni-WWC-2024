#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
   
    unordered_set<char> rows[9];  
    unordered_set<char> cols[9];  
    unordered_set<char> boxes[9]; 
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char num = board[i][j];
            if (num == '.') continue;  
            if (rows[i].count(num)) return false;
            rows[i].insert(num);
            
         
            if (cols[j].count(num)) return false;
            cols[j].insert(num);
            
          
            int boxIndex = (i / 3) * 3 + (j / 3);  
            if (boxes[boxIndex].count(num)) return false;
            boxes[boxIndex].insert(num);
        }
    }
    
    return true;  
}

int main() {
   
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '8', '.', '6', '.', '.', '3'},
        {'4', '.', '3', '.', '8', '3', '.', '8', '5'},
        {'7', '.', '.', '.', '2', '6', '.', '9', '4'},
        {'9', '6', '.', '.', '.', '.', '8', '7', '9'},
        {'2', '8', '5', '7', '9', '.', '3', '6', '1'},
        {'1', '.', '6', '5', '3', '7', '.', '.', '4'}
    };
    
    if (isValidSudoku(board)) {
        cout << "The Sudoku board is valid." << endl;
    } else {
        cout << "The Sudoku board is not valid." << endl;
    }

    return 0;
}
