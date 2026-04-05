class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> lPq;
        unordered_map<int, int> lMap;
        vector<int> lRes;
        lRes.reserve(nums.size() - k + 1);
        int lLeft = 0, lRight = 0;
        while (lRight < nums.size()) {
            lMap[nums[lRight]]++;
            lPq.push(nums[lRight]);
            if (lRight >= k - 1) {
                int lCurrMax = lPq.top();
                while (!lMap.contains(lCurrMax)) {
                    lPq.pop();
                    lCurrMax = lPq.top();
                }
                lRes.push_back(lCurrMax);
                lMap[nums[lLeft]]--;
                if (lMap[nums[lLeft]] == 0) {
                    lMap.erase(nums[lLeft]);
                }
                lLeft++;
            }
            lRight++;
        }
        return move(lRes);
    }
};
