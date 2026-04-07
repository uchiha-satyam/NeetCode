class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> lStack;
        int lRes;
        for (int i=0; i<tokens.size(); i++) {
            if (tokens[i] == "+") {
                lRes = lStack.top();
                lStack.pop();
                lRes += lStack.top();
                lStack.pop();
                lStack.push(lRes);
            }
            else if (tokens[i] == "-") {
                lRes = lStack.top();
                lStack.pop();
                lRes -= lStack.top();
                lStack.pop();
                lStack.push(-lRes);
            }
            else if (tokens[i] == "*") {
                lRes = lStack.top();
                lStack.pop();
                lRes *= lStack.top();
                lStack.pop();
                lStack.push(lRes);
            }
            else if (tokens[i] == "/") {
                lRes = lStack.top();
                lStack.pop();
                lStack.push(lStack.top()/lRes);
                lRes = lStack.top();
                lStack.pop();
                lStack.pop();
                lStack.push(lRes);
            }
            else {
                lStack.push(stoi(tokens[i]));
            }
        }
        return lStack.top();
    }
};
