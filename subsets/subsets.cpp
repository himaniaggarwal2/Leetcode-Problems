class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> list;
        std::sort(nums.begin(),nums.end());
        backtrack(list,vector<int> {},nums,0);
        return list;
    }
    void backtrack(vector<vector<int>> &list, vector<int> temp, vector<int> nums, int start){
        list.push_back(temp);
        for(int i=start;i<nums.size();i++){
            temp.push_back(nums[i]);
            backtrack(list,temp,nums,i+1);
            int n=temp.size();
            temp.pop_back();
        }
    }
};

