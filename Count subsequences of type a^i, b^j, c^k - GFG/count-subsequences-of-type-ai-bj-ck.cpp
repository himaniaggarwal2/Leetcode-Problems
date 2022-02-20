// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template 

class Solution{
  public:
    // s : given string
    // return the expected answer
    int fun(string &s) {
        long long a=0,ab=0,abc=0;
        int m=1e9+7;
        for(int i=0;i<s.size();i++){
            char ch= s[i];
            if(ch=='a'){
                a=(2*a+1)%m;
            }else if(ch=='b'){
                ab=(2*ab+a)%m;
            }else if(ch=='c'){
                abc=(2*abc+ab)%m;
            }
        }
        return abc%m;
    }
};

// { Driver Code Starts.
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.fun(s)<<endl;
    }
	return 0;
}  // } Driver Code Ends