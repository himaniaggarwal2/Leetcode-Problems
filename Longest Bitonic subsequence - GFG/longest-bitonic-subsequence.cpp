// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    int dp[200];//lis
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
	    }
	    
	    int dp2[200];//lds
	    for(int i=nums.size()-1;i>=0;i--){
	        int max=0;
	        for(int j=nums.size()-1;j>i;j--){
	            if(nums[j]<nums[i]){
	                if(dp2[j]>max){
	                    max=dp2[j];
	                }
	            }
	        }
	        dp2[i]=max+1;
	    }
	    
	   // for(int i=0;i<nums.size();i++){
	   //     cout<<dp[i]<<" ";
	   // }cout<<"\n";
	   // for(int i=0;i<nums.size();i++){
	   //     cout<<dp2[i]<<" ";
	   // }cout<<"\n";
	    int omax=0;
	    for(int i=0;i<nums.size();i++){
	        if(dp[i]+dp2[i]-1>omax){
	            omax=dp[i]+dp2[i]-1;
	        }
	    }
	    return omax;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends