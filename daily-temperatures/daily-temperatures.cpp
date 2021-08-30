class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> v;
        stack<int> st;
        int sz=temperatures.size();
        for(int i=sz-1;i>=0;i--){
            if(st.empty()) v.push_back(0);
            else if(sz>0 and temperatures[st.top()]>temperatures[i]) v.push_back(st.top()-i);
            else{
                while(st.size()>0 and temperatures[st.top()]<=temperatures[i]) st.pop();
                if(st.size()>0) v.push_back(st.top()-i);
                else v.push_back(0);
            }
            st.push(i);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};