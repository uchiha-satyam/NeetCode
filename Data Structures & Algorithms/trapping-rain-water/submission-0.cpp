class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> data(height.size());
        int lMaxH = 0;
        int lTotalWater = 0;
        for (int i=0; i<height.size(); i++) {
            data[i] = lMaxH;
            lMaxH = max(lMaxH, height[i]);
        }
        lMaxH = 0;
        for (int i=height.size()-1; i>=0; i--) {
            lTotalWater += max(0, min(lMaxH, data[i]) - height[i]);
            lMaxH = max(lMaxH, height[i]);
        }
        return move(lTotalWater);
    }
};
