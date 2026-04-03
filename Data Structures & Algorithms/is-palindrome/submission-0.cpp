class Solution {
public:
    bool isPalindrome(string s) {
        int lStart = 0, lEnd = s.size() - 1;
        while (lEnd > lStart) {
            if (!isalnum(s[lStart])) {
                lStart++;
                continue;
            }
            if (!isalnum(s[lEnd])) {
                lEnd--;
                continue;
            }
            if (tolower(s[lStart]) == tolower(s[lEnd])) {
                lStart++;
                lEnd--;
            }
            else {
                return false;
            }
        }
        return true;
    }
};
