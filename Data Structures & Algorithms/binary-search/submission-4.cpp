class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lLeft = 0, lRight = nums.size() - 1;
        int lMid;
        while (lLeft <= lRight) {
            lMid = lLeft + (lRight - lLeft)/2;
            if (nums[lMid] == target) {
                return lMid;
            }
            if (nums[lMid] > target) {
                lRight = lMid - 1;
            }
            else {
                lLeft = lMid + 1;
            }
        }
        return -1;
    }
};
