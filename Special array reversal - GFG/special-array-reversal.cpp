// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    string reverse(string str)
    { 
        auto len=str.size();
        int i=0;
        int j=len-1;
        while(i<j){ 
            while((i<j)&&(!isalpha(str[i])))
             i++;
            while((i<j)&&(!isalpha(str[j])))
             j--;
             
            swap(str[i++],str[j--]);
        }
                return str;
    } 
};


// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout <<ob.reverse(s) << endl;
    }
return 0;
}

  // } Driver Code Ends