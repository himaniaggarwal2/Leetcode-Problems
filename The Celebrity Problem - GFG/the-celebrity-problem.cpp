// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& arr, int n) 
    {
        stack<int> st;
        for(int i=0;i<n;i++){
            st.push(i);
        }
        
        while(st.size()>=2){
            int i= st.top();
            st.pop();
            int j= st.top();
            st.pop();
            
            if(arr[i][j]==1){
                st.push(j);
            }else{
                st.push(i);
            }
        }
        
        int pot = st.top();//potential celebrity
        st.pop();
        for(int i=0;i<n;i++){
            if(i!=pot){
                if(arr[i][pot]==0 or arr[pot][i]==1){
                    return -1;
                }
            }
        }
        return pot;
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
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends