class Solution {
public:
    int minAddToMakeValid(string str) {
        stack<char> st;
        if(str.size()==0) return 1;
        for(int i=0;i<str.size();i++){
            if(str[i]=='('){
                st.push(str[i]);
            }else{
                if(!st.empty() and st.top()=='('){
                    st.pop();
                }else{
                    st.push(str[i]);
                }
            }
        }
        return st.size();
    }
};