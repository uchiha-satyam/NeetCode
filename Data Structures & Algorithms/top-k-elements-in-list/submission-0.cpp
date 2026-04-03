class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // step 1:
        // create a map for <num, freq>
        unordered_map<int, int> lFreqMap;
        for (int i=0; i<nums.size(); i++) {
            lFreqMap[nums[i]]++;
        }
        // step 2:
        // create a maxHeap for <(freq, num)>
        priority_queue<pair<int, int>> lFreqQueue;
        for (const auto& [key, value] : lFreqMap) {
            lFreqQueue.push(make_pair(move(value), move(key)));
        }
        // step 3:
        // get top k elements
        vector<int> vec;
        vec.reserve(k);
        for (int i=0; i<k; i++) {
            vec.push_back(move(lFreqQueue.top().second));
            lFreqQueue.pop();
        }

        return move(vec);
    }
};
