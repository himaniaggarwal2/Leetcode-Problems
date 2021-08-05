#define fo(i,n) for(int i=0;i<n;i++)
class Solution {
public:
    void func(vector<vector<int>>& mat){
        int n=mat.size();
        int i,j;
        fo(i,n){
            for(j=i;j<n;j++){
                std::swap(mat[i][j],mat[j][i]);
            }
        }
        fo(i,n){
            fo(j,n/2){
                std::swap(mat[i][j],mat[i][n-1-j]);
            }
        }
    }
    bool checker(vector<vector<int>>& mat, vector<vector<int>>& target){
         int n=mat.size();
        int i,j;
        fo(i,n){
            fo(j,n){
                if(mat[i][j]!=target[i][j]) return false;
            }
        }
        return true;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int i,j;
        if(mat.size()!=target.size()) return false;
        int n=mat.size();
        int calls=0;
        func(mat);
        bool checker_val=checker(mat,target);
        if(checker_val) return checker_val;
        else{
            while(calls<4 and checker_val==false){
                func(mat);
                checker_val=checker(mat,target);
                calls++;
            }
            if(calls>=4 and checker_val==false) return false;
            
        }
        return true;
    }
};