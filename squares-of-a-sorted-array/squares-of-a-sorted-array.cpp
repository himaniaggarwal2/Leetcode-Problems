class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result;
        priority_queue<int,vector<int>,greater<int>> heap;
        int n=nums.size();
        for(int i=0;i<n;i++){
            heap.push(nums[i]*nums[i]);
        }
        while(!heap.empty()){
            result.push_back(heap.top());
            heap.pop();
        }
        return result;
    }
};