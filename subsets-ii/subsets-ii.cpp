class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> list;
        std::sort(nums.begin(),nums.end());
        backtrack(list,vector<int> {},nums,0);
        return list;
    }
    void backtrack(vector<vector<int>> &list, vector<int> temp, vector<int> nums, int start){
        list.push_back(temp);
        for(int i=start;i<nums.size();i++){
            if(i>start and nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            backtrack(list,temp,nums,i+1);
            temp.pop_back();
        }
    }
};