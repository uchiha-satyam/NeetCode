class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lLeft = 0, lRight = matrix.size() * matrix[0].size() - 1;
        while (lLeft <= lRight) {
            int lMid = lLeft + (lRight - lLeft)/2;
            if (matrix[lMid/matrix[0].size()][lMid%matrix[0].size()] == target) {
                return true;
            }
            else if (target < matrix[lMid/matrix[0].size()][lMid%matrix[0].size()]) {
                lRight = lMid - 1;
            }
            else {
                lLeft = lMid + 1;
            }
        }
        return false;
    }
};
