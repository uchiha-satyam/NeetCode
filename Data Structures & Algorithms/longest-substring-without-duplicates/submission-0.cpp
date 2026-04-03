class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> lPosition;
        int lLeft = 0, lRight = 0;
        int lMaxLength = 0;
        while (lRight < s.size()) {
            if (lPosition.contains(s[lRight]) && lPosition[s[lRight]] >= lLeft) {
                lLeft = lPosition[s[lRight]] + 1;
            }
            lPosition[s[lRight]] = lRight;
            lMaxLength = max(lMaxLength, lRight - lLeft + 1);
            lRight++;
        }
        return move(lMaxLength);
    }
};
