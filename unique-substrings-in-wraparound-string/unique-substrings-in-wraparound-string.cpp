class Solution {
public:
    bool is_next(char a,char b){
        return a=='z'? b=='a':a+1==b;
    }
    int findSubstringInWraproundString(string p) {
        unordered_map<char,int> mp;
        int max_length=1;
        
        for(size_t i=0;i<p.length();i++){
            if(mp.find(p[i])==mp.end())  mp[p[i]] = max_length;
            else    mp[p[i]]=std::max(max_length,mp[p[i]]);
            
            if(i+1<p.size() and is_next(p[i],p[i+1]))   max_length++;
            else    max_length=1;
        }
        
        int res=0;
        for(const pair<char,int> &kv:mp)    res+=kv.second;
        
        return res;
    }
};