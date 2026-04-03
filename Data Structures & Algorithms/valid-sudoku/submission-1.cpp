class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> lRow(board.size()), lColumn(board[0].size());
        vector<vector<unordered_set<int>>> lBox(3, vector<unordered_set<int>>(3));
        for (int r=0; r<board.size(); r++) {
            for (int c=0; c<board[0].size(); c++) {
                if (board[r][c] == '.') {
                    continue;
                }
                if (lRow[r].contains(board[r][c])) {
                    cout << board[r][c];
                    return false;
                }
                if (lColumn[c].contains(board[r][c])) {
                    cout << board[r][c];
                    return false;
                }
                if (lBox[r/3][c/3].contains(board[r][c])) {
                    cout << board[r][c];
                    return false;
                }
                lRow[r].insert(board[r][c]);
                lColumn[c].insert(board[r][c]);
                lBox[r/3][c/3].insert(board[r][c]);
            }
        }
        return true;
    }
};
