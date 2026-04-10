class Solution {
public:
    int findMin(vector<int> &nums) {
        int lLeft = 0, lRight = nums.size() - 1;
        int lMinPos = 0;
        while (lLeft <= lRight) {
            int lMid = lLeft + (lRight - lLeft)/2;
            if (lLeft == lRight) {
                return nums[lMid];
            }
            if (nums[lMid] < nums[lRight]) {
                lRight = lMid;
            }
            else {
                lLeft = lMid + 1;
            }
        }
        return -1;
    }
};
