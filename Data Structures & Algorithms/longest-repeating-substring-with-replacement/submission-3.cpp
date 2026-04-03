class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0, r=0;
        int mc = 0, ml = 0;
        unordered_map<char, int> f;
        while (r < s.size()) {
            f[s[r]]++;
            mc = max(mc, f[s[r]]);
            if (r-l+1-mc>k) {
                f[s[l]]--;
                l++;
            }
            else {
                ml = max(ml, r-l+1);
            }
            r++;
        }
        return ml;
    }
};
