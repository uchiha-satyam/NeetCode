class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size();
        for (int i=0; i<n; i++) {
            if (st.count(nums[i])) {
                return true;
            }
            st.insert(nums[i]);
        }
        return false;
    }
};