class Solution {
public:
    bool isPalindrome(int x) {
       if (x<0 || (x%10==0 && x!=0)) return false;
        int rev = 0;
        while (x>rev){
            rev = rev*10 + x%10;
            x = x/10;
        }
        return (x==rev || x==rev/10);
    }
};
/*
bool isPalindrome(int x) {
        int i=0;
        int copy=x;
        if(x<0) return false;
        map<int,int> mp;
        while(copy!=0){
            int val=copy%10;
            mp[val]++;
            copy=copy/10;
        }
        int count=0;
        // for(auto it=mp.begin();it!=mp.end();it++){
        //     cout<<it->first<<" "<<it->second<<endl;
        // }
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second % 2 != 0){
                count++;
            }
            if(count>1) return false;
        }
        return true;
    }
*/