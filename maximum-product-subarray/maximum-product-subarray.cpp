class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prev_max_product=nums[0];
        int n=nums.size();
        int result=nums[0];
        int prev_min_product=nums[0];
        int curr_min_product,curr_max_product;
        for(int i=1;i<n;i++){
            curr_max_product=max({prev_min_product*nums[i],prev_max_product*nums[i],nums[i]});
            curr_min_product=min({prev_min_product*nums[i],prev_max_product*nums[i],nums[i]});
            result=max(curr_max_product,result);
            prev_min_product=curr_min_product;
            prev_max_product=curr_max_product;
        }
        return result;
    }
};