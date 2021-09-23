class Solution {
public:
    int countGoodSubstrings(string s) {
        map<char,int> mp;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(i>2 and --mp[s[i-3]]==0) mp.erase(s[i-3]);
            ++mp[s[i]];
            if(mp.size()==3) count++;
        }
        return count;
    }
};