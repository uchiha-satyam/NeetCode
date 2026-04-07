class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> lResult(temperatures.size(), 0);
        stack<int> lStack;
        for (int i=0; i<temperatures.size(); i++) {
            while (!lStack.empty() && temperatures[lStack.top()] < temperatures[i]) {
                lResult[lStack.top()] = i - lStack.top();
                lStack.pop();
            }
            lStack.push(i);
        }
        return lResult;
    }
};
