class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> lCombinations;
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size()-2; i++) {
            int lLeft = i + 1, lRight = nums.size() - 1;
            int lTarget = 0 - nums[i];
            while (lLeft < lRight) {
                if (nums[lLeft] + nums[lRight] < lTarget) {
                    lLeft++;
                }
                else if (nums[lLeft] + nums[lRight] > lTarget) {
                    lRight--;
                }
                else {
                    lCombinations.insert({nums[i], nums[lLeft], nums[lRight]});
                    lLeft++;
                    lRight--;
                }
            }
        }
        vector<vector<int>> lSoln(lCombinations.begin(), lCombinations.end());
        return move(lSoln);
    }
};
