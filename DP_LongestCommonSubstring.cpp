// https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1#
#include <stdc++.h>
using namespace std;

int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        vector<vector<int> > memo(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(S1[i-1]==S2[j-1]) memo[i][j]=memo[i-1][j-1]+1;
            }
        }
        int mx=INT_MIN;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                mx=std::max(mx,memo[i][j]);
            }
        }
        return mx;
    }