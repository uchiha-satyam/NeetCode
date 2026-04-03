class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> lProduct(nums.size(), 1);
        for (int i=nums.size()-2; i>=0; i--) {
            lProduct[i] = lProduct[i+1] * nums[i+1];
        }
        int lLeftProduct = 1;
        for (int i=0; i<nums.size(); i++) {
            lProduct[i] *= lLeftProduct;
            lLeftProduct *= nums[i];
        }
        return move(lProduct);
    }
};
