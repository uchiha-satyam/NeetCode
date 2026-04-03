class Solution {
    string getFrequencyString(string str) {
        sort(str.begin(), str.end());
        return str;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> data;
        for (int i=0; i<strs.size(); i++) {
            data[getFrequencyString(strs[i])].push_back(strs[i]);
        }
        vector<vector<string>> vec;
        for (const auto& [key, value] : data) {
            vec.push_back(value);
        }
        return vec;
    }
};
