class Solution {
public:
    int maximumSwap(int num) {
        int mxIdx=-1,mxDigit=-1,leftIdx=-1,rightIdx=-1;
        string s=to_string(num);
        int n=s.length();
        for(int i=n-1;i>=0;i--){
            if(s[i]>mxDigit){
                mxDigit=s[i];
                mxIdx=i;
                continue;
            }
            if(s[i]<mxDigit){
                leftIdx=i;
                rightIdx=mxIdx;
            }
        }
        if(leftIdx==-1)return num;
        swap(s[leftIdx],s[rightIdx]);
        return stoi(s);
    }
};