class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int x) {
        int n=arr.size();
        vector<int> result;
        bool flag=false;
        if(arr.empty()) return {-1,-1};
        for(int i=0;i<n;i++){
            if(arr[i]==x){
                result.push_back(i);
                flag=true;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(arr[i]==x){
                result.push_back(i);
                break;
            }
        }
        if(flag==false) return {-1,-1};
        return result;
    }
};