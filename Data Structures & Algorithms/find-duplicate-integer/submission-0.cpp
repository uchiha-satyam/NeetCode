class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int lNum = -1;
        for (int i=0; i<nums.size(); i++) {
            if (nums[abs(nums[i])] < 0) {
                lNum = abs(nums[i]);
                break;
            }
            else {
                nums[abs(nums[i])] *= -1;
            }
        }
        for (int i=0; i<nums.size(); i++) {
            nums[i] = abs(nums[i]);
        }
        return lNum;
    }
};
