class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n=nums.size();
        int rightMin[100007];
        rightMin[n]=INT_MAX;
        for(int i=nums.size()-1;i>=0;i--){
            rightMin[i]=std::min(rightMin[i+1],nums[i]);
        }
        int leftMax=INT_MIN;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            leftMax=std::max(leftMax,nums[i]);
            if(leftMax<=rightMin[i+1]){
                ans=i;
                break;
            }
        }
        return ans+1;
    }
};