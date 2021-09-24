class Solution {
public:
    int longestPalindrome(string s) {
        if(s.size()==1) return 1;
        unordered_map<char,int> mp;
        int n=s.size();
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        int ans=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            ans+=(it->second)/2*2;
        }
        if(ans<s.length()) ans++;
        return ans;
    }
};