class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int rmin[n+1];
        rmin[n]=INT_MAX;
        for(int i=n-1;i>=0;i--){
            rmin[i]=std::min(rmin[i+1],arr[i]);
        }
        for(int i=0;i<n;i++){
            cout<<rmin[i]<<" ";
        }
        
        int curr_max=INT_MIN;
        int ans=0;
        for(int i=0;i<n;i++){
            curr_max=std::max(curr_max,arr[i]);
            if(curr_max<=rmin[i+1]) ans++;
        }
        return ans;
    }
};