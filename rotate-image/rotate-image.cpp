#define fo(i,n) for(int i=0;i<n;i++)
class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        int i,j;
        int n=arr.size();
        int m=arr[0].size();
        fo(i,n){
            for(int j=i;j<m;j++){
                
                std::swap(arr[i][j],arr[j][i]);
                
            }
        }
        fo(i,n){
            fo(j,m/2){
                std::swap(arr[i][j],arr[i][m-1-j]);
            }
        }
    }
};