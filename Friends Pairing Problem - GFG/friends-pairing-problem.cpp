// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        if(n<=2){
            return n;
        }
        long long a=1,b=2,c=2;
       for(long long i=3;i<=n;i++){
            c=b+(i-1)*a;
            c%=(1000000007);
            a=b;
            b=c;
        }
        return c;
    }
};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends