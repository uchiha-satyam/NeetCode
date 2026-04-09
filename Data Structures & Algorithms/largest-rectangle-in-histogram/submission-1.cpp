class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> lStack;
        vector<int> lLeftMin;
        int lRightMin = heights.size();
        int lResult = 0;
        lLeftMin.reserve(heights.size());
        for (int i=0; i<heights.size(); i++) {
            int& lHeight = heights[i];
            while (!lStack.empty() && heights[lStack.top()] >= lHeight) {
                lStack.pop();
            }
            if (lStack.empty()) {
                lLeftMin.push_back(-1);
            }
            else {
                lLeftMin.push_back(lStack.top());
            }
            lStack.push(i);
        }
        lStack = stack<int>();
        for (int i=heights.size()-1; i>=0; i--) {
            int& lHeight = heights[i];
            while (!lStack.empty() && heights[lStack.top()] >= lHeight) {
                lStack.pop();
            }
            if (lStack.empty()) {
                lRightMin = heights.size();
            }
            else {
                lRightMin = lStack.top();
            }
            lResult = max(lResult, lHeight*(lRightMin - lLeftMin[i] - 1));
            lStack.push(i);
        }
        return move(lResult);
    }
};
