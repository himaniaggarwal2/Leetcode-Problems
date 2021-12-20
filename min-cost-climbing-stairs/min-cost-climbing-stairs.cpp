class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1);  
        for (int i = 2; i <= n; i++) {
            int jumpOneStep = dp[i - 1] + cost[i - 1];  
            int jumpTwoStep = dp[i - 2] + cost[i - 2];  
            dp[i] = min(jumpOneStep, jumpTwoStep);
        }
        return dp[n];
    }
};



/*
int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,0);
        dp[n-1]=cost[n-1];
        dp[n-2]=std::min(cost[n-1],cost[n-2]);
        if(n>=3){
            for(int i=n-3;i>=0;i--){
                int min=INT_MAX;
                if(i+1<=n){
                    min=std::min({min,cost[i+1],cost[i+2]});
                }
                if(min!=INT_MAX){
                    dp[i] = dp[i+1]+min;
                }
            }
        }
        return dp[0];
}
*/