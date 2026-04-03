class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lMax = 0;
        int lProfit = 0;
        for (int i=prices.size()-1; i>=0; i--) {
            lProfit = max(lProfit, lMax - prices[i]);
            lMax = max(lMax, prices[i]);
        }
        return move(lProfit);
    }
};
