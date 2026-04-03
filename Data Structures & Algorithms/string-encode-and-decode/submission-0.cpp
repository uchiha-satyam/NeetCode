class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        int lCount = 0;
        for (const auto& str : strs) {
            s += str + ";";
            lCount++;
        }
        s = to_string(lCount) + ";" + s;
        return move(s);
    }

    vector<string> decode(string s) {
        vector<string> vec;
        string str = "";
        bool lIsFirstToken = true;
        for (const auto& ch : s) {
            if (ch == ';') {
                if (lIsFirstToken) {
                    vec.reserve(stoi(str));
                    lIsFirstToken = false;
                }
                else {
                    vec.push_back(str);
                }
                str = "";
                continue;
            }
            str += ch;
        }
        return move(vec);
    }
};
