class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> res(n);
        int i=1;
        int j=n-1;
        while(i<n){
            res[i] = nums[j];
            i+=2;
            j--;
        }
        i=0;
        while(i<n){
            res[i]=nums[j];
            i+=2;
            j--;
        }
        nums=res;
    }
};

/*
std::sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        vector<int> result;
        while(i<j){
            result.push_back(nums[i]);
            result.push_back(nums[j]);
            i++;
            j--;
        }
        nums=result;
*/

/*
for(int i=0;i<nums.size()-1;i++){
           if(i%2==0){
               if(nums[i+1]<nums[i]){
                   swap(nums[i],nums[i+1]);
               }
           }
           else if(i%2==1){
               if(nums[i+1]>nums[i]){
                   swap(nums[i],nums[i+1]);
               }
           }
       }
*/