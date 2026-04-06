class Solution {
public:
    bool isValid(string s) {
        stack<char> lStack;
        for (auto& lChar : s) {
            switch (lChar) {
                case ')':
                    if (lStack.empty() || lStack.top() != '(') {
                        return false;
                    }
                    else {
                        lStack.pop();
                    }
                    break;
                case '}':
                    if (lStack.empty() || lStack.top() != '{') {
                        return false;
                    }
                    else {
                        lStack.pop();
                    }
                    break;
                case ']':
                    if (lStack.empty() || lStack.top() != '[') {
                        return false;
                    }
                    else {
                        lStack.pop();
                    }
                    break;
                case '(':
                case '{':
                case '[':
                    lStack.push(lChar);
                    break;
                default:
                    return false;
            }
        }
        if (lStack.empty()) {
            return true;
        }
        return false;
    }
};
