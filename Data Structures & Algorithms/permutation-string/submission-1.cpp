class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> lFreqMap, lOrgMap;
        int lTotal = s1.size(), lLeft = 0, lRight = 0;
        for (int i=0; i<s1.size(); i++) {
            lFreqMap[s1[i]]++;
            lOrgMap[s1[i]]++;
        }
        while (lRight < s2.size()) {
            if (lRight - lLeft + 1 > s1.size()) {
                lFreqMap[s2[lLeft]]++;
                lTotal++;
                lLeft++;
            }
            lFreqMap[s2[lRight]]--;
            lTotal--;
            if (lFreqMap[s2[lRight]] < 0) {
                if (!lOrgMap.contains(s2[lRight])) {
                    lLeft = lRight+1;
                    lTotal = s1.size();
                    lFreqMap = lOrgMap;
                }
                else {
                    while (lLeft <= lRight && lFreqMap[s2[lRight]] != 0) {
                        lFreqMap[s2[lLeft]]++;
                        lTotal++;
                        lLeft++;
                    }
                }
            }
            if (lTotal == 0) {
                return true;
            }
            lRight++;
        }
        return false;
    }
};
