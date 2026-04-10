class Solution {
    int getTime(vector<int>& aInPiles, int& aInK) {
        int lTime = 0, lPos = -1;
        int lLeft = 0, lRight = aInPiles.size() - 1;
        while (lLeft <= lRight) {
            int lMid = lLeft + (lRight - lLeft)/2;
            if (aInPiles[lMid] <= aInK) {
                lPos = lMid;
                lLeft = lMid + 1;
            }
            else {
                lRight = lMid - 1;
            }
        }
        lTime = ++lPos;
        while (lPos < aInPiles.size()) {
            lTime += (aInPiles[lPos] + aInK - 1)/aInK;
            lPos++;
        }
        return lTime;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int lLeft = 1, lRight = piles.back();
        int lMinK = -1;
        while (lLeft <= lRight) {
            int lMid = lLeft + (lRight - lLeft)/2;
            if (getTime(piles, lMid) <= h) {
                lMinK = lMid;
                lRight = lMid - 1;
            }
            else {
                lLeft = lMid + 1;
            }
        }
        return lMinK;
    }
};
