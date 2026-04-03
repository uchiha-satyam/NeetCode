class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> lFreqMap;
        int lTotal = s1.size(), lLeft = 0, lRight = 0, lNegative = 0;
        for (int i=0; i<s1.size(); i++) {
            lFreqMap[s1[i]]++;
        }
        while (lRight < s2.size()) {
            if (lRight - lLeft + 1 > s1.size()) {
                if (lFreqMap.contains(s2[lLeft])) {
                    lFreqMap[s2[lLeft]]++;
                    if (lFreqMap[s2[lLeft]] == 0) {
                        lNegative--;
                    }
                    lTotal++;
                }
                lLeft++;
            }
            if (lFreqMap.contains(s2[lRight])) {
                lFreqMap[s2[lRight]]--;
                lTotal--;
                if (lFreqMap[s2[lRight]] == -1) {
                    lNegative++;
                }
                if (lTotal == 0 && lNegative == 0) {
                    return true;
                }
            }
            lRight++;
        }
        return false;
    }
};
