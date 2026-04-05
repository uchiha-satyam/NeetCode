class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> lDq;
        vector<int> lRes;
        lRes.reserve(nums.size() - k + 1);
        for (int i=0; i<nums.size(); i++) {
            while (!lDq.empty() && nums[lDq.back()] <= nums[i]) {
                lDq.pop_back();
            }
            lDq.push_back(i);
            if (!lDq.empty() && lDq.front() <= i-k) {
                lDq.pop_front();
            }
            if (i >= k-1) {
                lRes.push_back(nums[lDq.front()]);
            }
        }
        return move(lRes);
    }
};
