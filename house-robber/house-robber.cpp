class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int l1,l2,ob1,ob2;
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        ob1=nums[0];
        ob2=0;
        for(int i=1;i<n;i++){
            l1=nums[i]+ob2;  //include
            l2=std::max(ob1,ob2);
            
            ob1=l1;
            ob2=l2;
//             l0=nums[i];
//             l1=ob1+nums[i];
            
//             ob1=std::max(l0,l1);
        }
        return std::max(l1,l2);
    }
};