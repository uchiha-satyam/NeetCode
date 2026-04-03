class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int lLongestLength = 1, lLength = 1;
        sort(nums.begin(), nums.end());
        for (int i=1; i<nums.size(); i++) {
            if (nums[i]-1 == nums[i-1]) {
                lLength++;
            }
            else if (nums[i] == nums[i-1]) {
                continue;
            }
            else {
                lLength = 1;
            }
            lLongestLength = max(lLongestLength, lLength);
        }
        return move(lLongestLength);
    }
};
