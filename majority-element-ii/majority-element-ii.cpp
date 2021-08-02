class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int val1=nums[0];
        int count1=0;
        int val2=nums[0];
        int count2=0;
        for(int i=0;i<nums.size();i++){
            if(val1==nums[i]) count1++;
            else if(val2==nums[i]) count2++;
            else if(count1==0){
                val1=nums[i];
                count1=1;
            }else if(count2==0){
                val2=nums[i];
                count2=1;
            }else{
                count1--;
                count2--;
            }
        }
        int freq1=0;
        int freq2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==val1)freq1++;
            else if(nums[i]==val2) freq2++;
        }
        vector<int> ans;
        int n=nums.size();
        if(freq1>n/3) ans.push_back(val1);
        if(freq2>n/3) ans.push_back(val2);
        return ans;
    }
};