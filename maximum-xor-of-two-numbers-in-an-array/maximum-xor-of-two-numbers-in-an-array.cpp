class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxResult=0;
        int mask=0;
        for(int i=31;i>=0;i--){
            mask=mask|(1<<i);
            std::set<int> set;
            for(int num: nums){
                int leftPartOfNum = num & mask;
                set.insert(leftPartOfNum);
            }
            
            int greedyTry = maxResult | (1<<i);
            for(int leftPartOfNum: set){
                int anotherNum = leftPartOfNum ^ greedyTry;
                
                if(set.find(anotherNum)!=set.end()){
                    maxResult = greedyTry;
                    break;
                }
            }
        }
        return maxResult;
    }
};