class Solution {
public:
    int m=1e9+7;
    int numTrees(int n) {
        vector<long long> cat(n+1);
        cat[0]=1;
        cat[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<i;j++){
                cat[i]+=((cat[j]%m)*(cat[i-1-j]%m))%m;
            }
        }
        return (int)cat[n];
    }
};