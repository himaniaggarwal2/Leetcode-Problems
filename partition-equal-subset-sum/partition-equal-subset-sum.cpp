class Solution {
public:
    
bool canPartition(vector<int>& nums) {
    int totalSum=0;
    int n=nums.size();

    for(int i=0;i<n;i++){
        totalSum+=nums[i];
    }
    if(totalSum%2 != 0) return false;

    vector<vector<bool> > temp(n+1,vector<bool>((totalSum/2)+1,false));
    
    for(int i=0;i<=n;i++){
        temp[i][0]= true;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=(totalSum/2);j++){
            if(nums[i-1]<=j)
                temp[i][j]=temp[i-1][j] or temp[i-1][j-nums[i-1]];
            else
                temp[i][j]=temp[i-1][j];
        }
    }
    return temp[n][totalSum/2];
    }
};