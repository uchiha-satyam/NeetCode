class Solution {
    // Data Memebers
    unordered_map<char, int> freqMap;
    int positives = 0;

    // Member Functions
    void fillMap (string& aInStr) {
        for (int i=0; i<aInStr.size(); i++) {
            freqMap[aInStr[i]]++;
        }
        positives = freqMap.size();
    }
    void include (char aInChar) {
        if (freqMap.contains(aInChar)) {
            freqMap[aInChar]--;
            if (freqMap[aInChar] == 0) {
                positives--;
            }
        }
    }
    void exclude (char aInChar) {
        if (freqMap.contains(aInChar)) {
            freqMap[aInChar]++;
            if (freqMap[aInChar] == 1) {
                positives++;
            }
        }
    }
    void increaseLeft (int& aInLeft, int& aInRight, string& aInStr) {
        if (aInLeft >= aInStr.size()) {
            return;
        }
        exclude(aInStr[aInLeft]);
        aInLeft++;
        if (aInLeft > aInRight) {
            increaseRight(aInRight, aInStr);
        }
    }
    void increaseRight (int& aInRight, string& aInStr) {
        if (aInRight >= aInStr.size()) {
            return;
        }
        aInRight++;
        include(aInStr[aInRight]);
    }
    void updateResult (int& aInLeft, int& aInRight, int& aInOutMinLength, string& aInStr, string& aOutResult) {
        if (positives != 0) {
            return;
        }
        int lLength = aInRight - aInLeft + 1;
        if (lLength < aInOutMinLength) {
            aInOutMinLength = lLength;
            aOutResult = aInStr.substr(aInLeft, lLength);
        }
    }
public:
    string minWindow(string s, string t) {
        string lResult = "";
        int lMinLength = INT_MAX, lLeft = 0, lRight = 0;
        fillMap(t);
        include(s[lRight]);
        while (lRight < s.size()) {
            if (positives == 0) {
                updateResult(lLeft, lRight, lMinLength, s, lResult);
                increaseLeft(lLeft, lRight, s);
            }
            else if (!freqMap.contains(s[lLeft])) {
                increaseLeft(lLeft, lRight, s);
            }
            else {
                increaseRight(lRight, s);
            }
        }
        updateResult(lLeft, lRight, lMinLength, s, lResult);
        return lResult;
    }
};
