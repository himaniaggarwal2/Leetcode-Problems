class Solution {
public:
    bool isHappy(int n) {
        if(n<=0) return false;
        if(n==1) return true;
        
        unordered_set<int> seen;
        int nextVal=0;
        for(;;){
            nextVal=0;
            while(n>0){
                nextVal+=(n%10)*(n%10);
                n/=10;
            }
            if(nextVal==1) return true;
            if(seen.count(nextVal)>0) return false;
            seen.insert(nextVal);
            n=nextVal;
        }
    }
};