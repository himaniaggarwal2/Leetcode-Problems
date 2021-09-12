class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prev_max=nums[0],prev_min=nums[0],curr_max,curr_min;
        int result=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            curr_min=std::min({prev_min*nums[i],prev_max*nums[i],nums[i]});
            curr_max=std::max({prev_min*nums[i],prev_max*nums[i],nums[i]});
            result=std::max(curr_max,result);
            prev_min=curr_min;
            prev_max=curr_max;
        }
        return result;
    }
};