class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> list;
        std::sort(nums.begin(),nums.end());
        bool arr[9]={false};
        backtrack(list,vector<int> {}, nums, arr);
        return list;
    }
    void backtrack(vector<vector<int>> &list, vector<int> temp, vector<int> nums, bool used[]){
        if(temp.size() == nums.size()){
            list.push_back(temp);
        }else{
            for(int i=0;i<nums.size();i++){
                if(used[i] || i>0 && nums[i] == nums[i-1] && !used[i-1]) 
                    continue;
                used[i]=true;
                temp.push_back(nums[i]);
                backtrack(list,temp,nums,used);
                used[i]=false;
                temp.pop_back();
            }
        }
    }
};