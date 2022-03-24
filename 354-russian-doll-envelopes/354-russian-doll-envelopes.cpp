class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),[](vector<int> &a, vector<int> &b){
            return (a[0]<b[0] || (a[0]==b[0] && (a[1]>b[1])));
        });
        
        int dp[envelopes.size()];
        int ans=0;
        
        for(int i=0;i<envelopes.size();i++){
            int val = envelopes[i][1];
            int lo=0;
            int hi=ans;
            
            while(lo<hi){
                int mid= lo+(hi-lo)/2;
                
                if(dp[mid] < val){
                    lo=mid+1;
                }
                else{
                    hi=mid;
                }
            }
            
            dp[lo] = val;
            
            if(lo==ans) 
                ans++;
            
        }
        return ans;
    }
};

/*
class Solution {
public:
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
       sort(envelopes.begin(), envelopes.end(),[](vector<int> &a,vector<int> &b){ 
        return (a[0]<b[0] || (a[0]==b[0] && (a[1]>b[1])));
    });
        int dp[100005]={INT_MIN};
        
        int omax=0;
        for(int i=0;i<envelopes.size();i++){
            int max=0;
            for(int j=0;j<i;j++){
                if(envelopes[j][1]<envelopes[i][1] and envelopes[j][0]<envelopes[i][0]){
                    max=std::max(max,dp[j]);
                }
            }
            dp[i] = max + 1;
            
            if(dp[i] > omax){
                omax = dp[i];
            }
        }
       return omax; 
    }
};
*/