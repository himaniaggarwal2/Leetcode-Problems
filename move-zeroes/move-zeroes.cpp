class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count_of_zeros=0;
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count_of_zeros++;
            }
            else{
                result.push_back(nums[i]);
            }
        }
        for(int i=0;i<count_of_zeros;i++){
            result.push_back(0);
        }
        nums=result;
    }
};