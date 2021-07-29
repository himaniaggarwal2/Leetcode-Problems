//https://practice.geeksforgeeks.org/problems/shortest-common-supersequence0322/1#

class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    // int lcs(vector<vector<int> > &memo,string X, string Y, int m, int n){
    //     if(memo[m][n]==-1) return memo[m][n];
    //     if(m==0 or n==0) memo[m][n]=0;
    //     else{
    //         if(X[m-1]==Y[n-1]) memo[m][n]= lcs(memo,X,Y,m-1,n-1)+1;
    //         else memo[m][n]=std::max(lcs(memo,X,Y,m-1,n),lcs(memo,X,Y,m,n-1));
    //     }
    //     return memo[m][n];
    // }
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        vector<vector<int> > memo(m+1,vector<int>(n+1,-1));
        // int val=lcs(memo,X,Y,m,n);
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0 or j==0) memo[i][j]=0;
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(X[i-1]==Y[j-1]) memo[i][j]=memo[i-1][j-1]+1;
                else memo[i][j]=std::max(memo[i-1][j],memo[i][j-1]);
            }
        }
        return m+n-memo[m][n];
    }
};