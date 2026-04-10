class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lRow = -1, lColumn = -1;
        int lLeft = 0, lRight = matrix.size() - 1;
        while (-1 == lRow && lLeft <= lRight) {
            int lMid = lLeft + (lRight - lLeft)/2;
            if (matrix[lMid].front() <= target && matrix[lMid].back() >= target) {
                lRow = lMid;
            }
            else if (target < matrix[lMid].front()) {
                lRight = lMid - 1;
            }
            else {
                lLeft = lMid + 1;
            }
        }
        if (-1 == lRow) {
            return false;
        }
        lLeft = 0, lRight = matrix[lRow].size() - 1;
        while (-1 == lColumn && lLeft <= lRight) {
            int lMid = lLeft + (lRight - lLeft)/2;
            if (matrix[lRow][lMid] == target) {
                lColumn = lMid;
            }
            else if (target < matrix[lRow][lMid]) {
                lRight = lMid - 1;
            }
            else {
                lLeft = lMid + 1;
            }
        }
        return !(-1 == lColumn);
    }
};
