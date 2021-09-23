class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int temp_max=0;
        int curr_max=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){ 
                temp_max++;
                curr_max=std::max(temp_max,curr_max);
            }
            else if(nums[i]==0){
                temp_max=0;
            }
        }
        return curr_max;
    }
};