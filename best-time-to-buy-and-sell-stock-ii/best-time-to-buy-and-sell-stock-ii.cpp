class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ini=prices[0],end=prices[0];
        int profit=0;
        for(int i=1;i<prices.size();i++){
            if(end<prices[i]){
                
                end=prices[i];
            }
            else if(end>prices[i]){
                
                profit+=(end-ini);
                ini=prices[i];
                end=prices[i];
            }
        }
        profit+=(end-ini);
        return profit;
    }
};