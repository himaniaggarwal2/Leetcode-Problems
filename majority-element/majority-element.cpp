class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int val=nums[0];
        int count=1;
        for(int i=1;i<nums.size();i++){
            if(val==nums[i]){
                count++;
            }
            else if(count==0){
                val=nums[i];
                count=1;
            }else{
                count--;
            }
        }
        return val;
    }
};