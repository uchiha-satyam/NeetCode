class Solution {
    int searchHelper(vector<int>& aInNums, int aInLeft, int aInRight, int& aInTarget) {
        if (aInLeft < 0 && aInRight >= aInNums.size())  {
            return -1;
        }
        if (aInNums[aInLeft] > aInTarget || aInTarget > aInNums[aInRight]) {
            return -1;
        }
        int lMid = aInLeft + (aInRight - aInLeft)/2;
        if (aInTarget == aInNums[lMid]) {
            return lMid;
        }
        else if (aInTarget < aInNums[lMid]) {
            return searchHelper(aInNums, aInLeft, lMid-1, aInTarget);
        }
        return searchHelper(aInNums, lMid+1, aInRight, aInTarget);
    }
public:
    int search(vector<int>& nums, int target) {
        return searchHelper(nums, 0, nums.size()-1, target);
    }
};
