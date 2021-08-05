#define fo(i,n) for(int i=0;i<=n;i++)
class Solution {
public:
    int longestCommonSubsequence(string &a, string &b) {
      vector<vector<short>> m(a.size() + 1, vector<short>(b.size() + 1));
      for (auto i = 1; i <= a.size(); ++i)
        for (auto j = 1; j <= b.size(); ++j)
          if (a[i - 1] == b[j - 1]) m[i][j] = m[i - 1][j - 1] + 1;
          else m[i][j] = max(m[i - 1][j], m[i][j - 1]);
      return m[a.size()][b.size()];
    }
};
/*
int lcs(vector<vector<int> > &memo,string s1,string s2,int m,int n){
        if(memo[m][n]!=-1) return memo[m][n];
        
        if(m==0 or n==0) memo[m][n]=0;
        else{
            if(s1[m-1]==s2[n-1]) memo[m][n] = 1+ lcs(memo,s1,s2,m-1,n-1);
            else memo[m][n]= std::max(lcs(memo,s1,s2,m,n-1),lcs(memo,s1,s2,m-1,n));
        }
        return memo[m][n];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        vector<vector<int> > memo(m+1,vector<int>(n+1,-1));
        
        int val=lcs(memo,text1,text2,m,n); 
        
        return val;
    }
*/