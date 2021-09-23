class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum=0;
        int count=0;
        int t=k*threshold;
        for(int i=0;i<arr.size();i++){
            if(i>k-1){
                sum-=arr[i-k];
            }
            sum+=arr[i];
            // cout<<sum<<endl;
            
            if(i>=k-1 and sum>=t)  count++;
        }
        return count;
    }
};