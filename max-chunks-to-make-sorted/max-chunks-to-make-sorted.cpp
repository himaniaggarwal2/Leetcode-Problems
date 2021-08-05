class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxindx=INT_MIN;
        int ans=0;
        for(int i=0;i<arr.size();i++){
            maxindx=max(maxindx,arr[i]);
            if(i==maxindx) ans++;
        }
        return ans;
    }
};