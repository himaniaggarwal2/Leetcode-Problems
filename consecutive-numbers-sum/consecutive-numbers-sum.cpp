class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int count=0,i=1;
        while(N>0){
            N=N-i;
            if(N%i==0){
                count++;
            }
            i++;
        }
        return count;
    }
};