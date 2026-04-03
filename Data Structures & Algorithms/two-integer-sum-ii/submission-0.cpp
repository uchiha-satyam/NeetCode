class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lLeft = 0, lRight = numbers.size() - 1;
        while (lLeft < lRight) {
            if (numbers[lLeft] + numbers[lRight] < target) {
                lLeft++;
            }
            else if (numbers[lLeft] + numbers[lRight] > target) {
                lRight--;
            }
            else {
                return move(vector<int>{lLeft+1, lRight+1});
            }
        }
        return move(vector<int>{-1, -1});
    }
};
