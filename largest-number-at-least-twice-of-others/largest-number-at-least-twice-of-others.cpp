class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max1=INT_MIN,max2=INT_MIN;
        int index1=-1;
        if(nums.size()==1) return 0;
        for(int i=0;i<nums.size();i++){
            if(max1<=nums[i]){
                max2=max1;
                max1=nums[i];
                index1=i;
            }
            else if(max2<=nums[i]){
                max2=nums[i];
            }
        }
        if(max1>=2*max2) return index1;
        
        return -1;
    }
};