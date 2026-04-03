class Solution {
public:
    int maxArea(vector<int>& heights) {
        map<int, int> lRecord;
        int lMaxArea = 0;
        auto lMax = [&]() {
            for (int i=0; i<heights.size(); i++) {
                cout << heights[i] << ", ";
                auto lIt = lRecord.lower_bound(heights[i]);
                if (lIt != lRecord.end()) {
                    lMaxArea = max(lMaxArea, heights[i] * (i - (lIt->second)));
                    // lRecord[heights[i]] = lIt->second;
                }
                else {
                    lRecord[heights[i]] = i;
                }
            }
        };
        lMax();
        cout << endl;
        lRecord.clear();
        reverse(heights.begin(), heights.end());
        lMax();
        return move(lMaxArea);
    }
};
