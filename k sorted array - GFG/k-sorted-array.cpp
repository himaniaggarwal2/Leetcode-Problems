// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    string isKSortedArray(int arr[], int n, int k)
    {
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]=i;
        }
        sort(arr,arr+n);
        for(int i=0;i<n;i++){
            int idx= mp[arr[i]];
            if(abs(idx-i)>k){
                return "No";
            }
        }
        return "Yes";
    }
    /*
    vector<int> br;
        for(int i=0;i<n;i++){
            br.push_back(arr[i]);
        }
        std::sort(br.begin(),br.end());
        priority_queue<int,vector<int>,greater<int>> heap;
        for(int i=0;i<k;i++)    heap.push(arr[i]);
        vector<int> res;
        for(int i=k;i<n;i++){
            if(i>0 and arr[i]>=heap.top()){
                res.push_back(heap.top());
                heap.pop();
                heap.push(arr[i]);
            }
            else if(i==0){
                res.push_back(arr[i]);
                heap.push(arr[i]);
            }
            else{
                res.push_back(arr[i]);
            }
        }
        while(!heap.empty()){
            res.push_back(heap.top());
            heap.pop();
        }
        for(int i=0;i<br.size();i++){
            if(res[i]!=br[i]) {
                return "No";
            }
        }
        return "Yes";
    */
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    cin>>k;
	    Solution ob;
	cout <<ob.isKSortedArray(arr, n, k)<<endl;
	}
	return 0;	 
}  // } Driver Code Ends