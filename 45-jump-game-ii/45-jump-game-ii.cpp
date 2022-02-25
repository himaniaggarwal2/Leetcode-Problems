class Solution {
public:
    int jump(vector<int>& nums) {
        int dp[nums.size()];
        for(int i=0;i<nums.size()-1;i++){
            dp[i]=-1;
        }
        dp[nums.size()-1]=0;
        for(int i=nums.size()-2;i>=0;i--){
            int steps= nums[i];
            int min = INT_MAX;
            for(int j=1;j<=steps and i+j<nums.size();j++){
                if(dp[i+j]!=-1 and dp[i+j]<min){
                    min=dp[i+j];
                }
            }
            if(min!=INT_MAX){
                dp[i]=min+1;
            }
        }
        return dp[0];
    }
};