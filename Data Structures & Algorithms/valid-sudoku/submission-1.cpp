class Solution {
public:

// sr = starting row
// er = ending row
// sc = starting column
// ec = ending column

// Function to validate nine 3x3 sub-boxes
    // bool traversal(vector<vector<char>>& board, int sr, int er, int sc, int ec) {
    //     set<char> s;

    //     for(int i=sr;i<=er;i++) {
    //         for(int j=sc;j<=ec;j++) {
    //             if(board[i][j]=='.')
    //             continue;

    //             auto result=s.insert(board[i][j]);
    //             if(result.second==false)
    //             return false;
    //         }
    //     }

    //     return true;
    // }

    bool isValidSudoku(vector<vector<char>>& board) {
// Optimized Approach, using Hashing, TC=O(1), SC=O(1), fixed (9x9) board
// For n x n board: TC=O(n^2), SC=O(n^2)

        unordered_set<string> s;

        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                if(board[i][j]=='.')
                continue;

                string row=string(1, board[i][j]) + "_ROW_" + to_string(i);
                string col=string(1, board[i][j]) + "_COL_" + to_string(j);
                string box=string(1, board[i][j]) + "_BOX_" + to_string(i/3) + "_" + to_string(j/3);

                auto result1=s.insert(row);
                auto result2=s.insert(col);
                auto result3=s.insert(box);

                if(!result1.second || !result2.second || !result3.second)
                return false;
            }
        }

        return true;

/*
// Optimized Approach, one pass early exit, TC=O(1), SC=O(1), fixed (9x9) board
// For n x n board: TC=O(n^2), SC=O(n^2)

        vector<vector<bool>> rows(9, vector<bool>(9, false));
        vector<vector<bool>> cols(9, vector<bool>(9, false));
        vector<vector<bool>> boxes(9, vector<bool>(9, false));

        for(int i=0;i<9;i++) {

            for(int j=0;j<9;j++) {

                if(board[i][j]=='.')
                    continue;

                int num=board[i][j]-'1';

                int boxIndex=(i/3) * 3 + (j/3);

                if(rows[i][num] || cols[j][num] || boxes[boxIndex][num])
                    return false;

                rows[i][num]=true;
                cols[j][num]=true;
                boxes[boxIndex][num]=true;
            }
        }

        return true;
*/

/*
// Brute Force Approach, TC=O(1), SC=O(1)  (fixed 9x9 board)
// For n x n board: TC=O(n^2), SC=O(n)

        // validating rows
        for(int i=0;i<9;i++) {
            set<char> s;
            for(int j=0;j<9;j++) {
                if(board[i][j]=='.')
                continue;

                auto result=s.insert(board[i][j]);
                if(result.second==false)
                return false;
            }
        }

        // validating columns
        for(int i=0;i<9;i++) {
            set<char> s;
            for(int j=0;j<9;j++) {
                if(board[j][i]=='.')
                continue;

                auto result=s.insert(board[j][i]);
                if(result.second==false)
                return false;
            }
        }

        // validating nine 3x3 sub-boxes
        for(int sr=0;sr<9;sr+=3) {
            int er=sr+2;
            for(int sc=0;sc<9;sc+=3) {
                int ec=sc+2;
                // calling traversing function to validate sub-boxes
                if(!traversal(board, sr, er, sc, ec))
                return false;
            }
        }

        return true;
*/
    }
};
