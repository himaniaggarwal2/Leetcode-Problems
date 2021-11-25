class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> list;
        // std::sort(nums.begin(),nums.end()); //not necessary
        backtrack(list,vector<int> {},nums);
        return list;
    }
     void backtrack(vector<vector<int>> &list, vector<int> temp, vector<int> nums){
        if(temp.size()==nums.size())
            list.push_back(temp);
        else
            for(int i=0;i<nums.size();i++){
                if(std::find(temp.begin(),temp.end(),nums[i])!=temp.end()) continue;
                temp.push_back(nums[i]);
                backtrack(list,temp,nums);
                temp.pop_back();
            }
    }
};