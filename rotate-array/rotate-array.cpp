class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        reverse(nums.begin(),nums.begin()+nums.size()-(k%nums.size()));// it will avoid the case of when size of k is smaller than size of array then there wont be any changes but when size of k is greater than the array then it will repeat itself so we need to make changes only to the remainder number of times like if k=10 and size of array is 2 then it will become 0 changes on size 2 array 
        reverse(nums.begin()+nums.size()-(k%nums.size()),nums.end());
        reverse(nums.begin(),nums.end());
    }
};