class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> mp;
        if(deck.size()==1) return false;
        for(int i=0;i<deck.size();i++){
            mp[deck[i]]++;
        }
        if(mp.size()==1) return true;
        
        int result=mp.begin()->second;
        for(auto it=mp.begin();it!=mp.end();it++){
           result=__gcd(result,it->second);
        }
        
        if(result>1) return true;
        else return false;
    }
};