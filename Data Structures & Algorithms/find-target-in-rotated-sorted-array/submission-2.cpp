class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lLeft = 0, lRight = nums.size() - 1;
        while (lLeft <= lRight) {
            int lMid = lLeft + (lRight - lLeft)/2;
            if (nums[lMid] == target) {
                return lMid;
            }
            if (nums[lLeft] < nums[lRight]) {
                if (nums[lMid] > target) {
                    lRight = lMid - 1;
                }
                else {
                    lLeft = lMid + 1;
                }
            }
            else if (nums[lMid] >= nums[lLeft]) {
                if (target > nums[lMid] || target < nums[lLeft]) {
                    lLeft = lMid + 1;
                }
                else {
                    lRight = lMid - 1;
                }
            }
            else {
                if (target < nums[lMid] || target > nums[lRight]) {
                    lRight = lMid - 1;
                }
                else {
                    lLeft = lMid + 1;
                }
            }
        }
        return -1;
    }
};
