class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int omax=0;
        int dp[2500]={0};
        for(int i=0;i<nums.size();i++){
            int max=0;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    if(dp[j]>max){
                        max=dp[j];
                    }
                }
            }
            dp[i]=max+1;
            
            if(dp[i]>omax) omax=dp[i];
        }
        return omax;
    }
};