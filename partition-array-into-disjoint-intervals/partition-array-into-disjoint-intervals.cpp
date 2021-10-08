class Solution {
public:
    int partitionDisjoint(vector<int>& arr) {
        int n = arr.size();
        int max = arr[0];
        int tmp_max = arr[0];
        int l = 0;
        
        for(int i=1;i<n;i++) {
            if(max > arr[i]) {
                l = i;
                max = tmp_max;
            }
            else 
                tmp_max = std::max(tmp_max, arr[i]);
        }
        
        return l + 1;
    }
};