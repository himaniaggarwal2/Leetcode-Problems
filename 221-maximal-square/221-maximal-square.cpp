class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans=0;
        int dp[matrix.size()][matrix[0].size()];
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                dp[i][j]=-1;    
            }
        }
        for(int i=matrix.size()-1;i>=0;i--){
            for(int j=matrix[0].size()-1;j>=0;j--){
                if(i==matrix.size()-1 and j==matrix[0].size()-1){
                    if(matrix[i][j]=='0'){
                        dp[i][j]=0;
                    }else{
                        dp[i][j]=1;
                    } 
                    if(dp[i][j]>ans){
                        ans=dp[i][j];
                    }
                }else if(i==matrix.size()-1){
                   if(matrix[i][j]=='0'){
                        dp[i][j]=0;
                    }else{
                        dp[i][j]=1;
                    }
                    if(dp[i][j]>ans){
                        ans=dp[i][j];
                    }
                }else if(j==matrix[0].size()-1){
                    if(matrix[i][j]=='0'){
                        dp[i][j]=0;
                    }else{
                        dp[i][j]=1;
                    }
                    if(dp[i][j]>ans){
                        ans=dp[i][j];
                    }
                }else{
                    if(matrix[i][j]=='0'){
                        dp[i][j]=0;
                    }
                    else {
                        dp[i][j]=min({dp[i+1][j],dp[i+1][j+1],dp[i][j+1]})+1;
                    }
                    if(dp[i][j]>ans){
                        ans=dp[i][j];
                    }
                }
            }
        }
        
        return ans*ans;
    }
};