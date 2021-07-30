class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> rr;
        for(int i=0;i<nums.size();i++){
            rr.push_back(nums[i]*nums[i]);
        }
        std::sort(rr.begin(),rr.end());
        return rr;
    }
};