class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(res,"",0,0,n);
        return res;
    }
    
    void helper(vector<string> &res, string str, int open, int close, int n){
        if(str.size()==n*2){
            res.push_back(str);
            return;
        }
        if(open<n){
            helper(res,str+"(",open+1,close,n);
        }
        if(close<open){
            helper(res,str+")",open,close+1,n);
        }
    }
};