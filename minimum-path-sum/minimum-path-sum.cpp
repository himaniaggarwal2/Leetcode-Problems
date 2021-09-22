class Solution {
public:
    // int pathSum(vector<vector<int>> grid,int row,int column,vector<vector<int>>& dp){
    //     // if(row<0 or column<0) return INT_MAX;
    //     if(row==0 and column==0) return grid[0][0];
    //     if(dp[row][column]!=0){
    //         return dp[row][column];
    //     }
    //     int up=pathSum(grid,row-1,column,dp);
    //     int down=pathSum(grid,row,column-1,dp);
    //     int ans=std::min(up,down)+grid[row][column];
    //     dp[row][column]=ans;
    //     return ans;
    // }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size()-1;
        int m=grid[0].size()-1;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        dp[n][m]=grid[n][m];
        
        for(int i=n-1;i>=0;i--){
            dp[i][m]=grid[i][m]+dp[i+1][m];
        }
        for(int j=m-1;j>=0;j--){
            dp[n][j]=grid[n][j]+dp[n][j+1];
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                dp[i][j]=std::min(dp[i+1][j],dp[i][j+1])+grid[i][j];
            }
        }
        
//         for(int i=0;i<=n;i++){
//             for(int j=0;j<=m;j++){
//                 cout<<dp[i][j]<<" ";
                
//             }cout<<"\n";
//         }
        
    
        return dp[0][0];
    }
};