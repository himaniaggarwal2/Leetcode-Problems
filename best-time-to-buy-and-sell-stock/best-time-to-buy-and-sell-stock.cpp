class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int minimum=prices[0];
        if(prices.size()==1) return 0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]<minimum){
                minimum=prices[i];
            }
            if(profit<prices[i]-minimum){
                profit=prices[i]-minimum;
            }
        }
        return profit;
    }
};