class Solution {
public:
    int reachNumber(int target) {
        target=std::abs(target);
        int sum=0;
        int jump=0;
        for(int i=1;i<=target+10;i++){
            if(sum==target) return jump;
            else if(sum<target){
                jump++;
                sum+=jump;
            }
            else if(sum>target){
                int diff=sum-target;
                if(diff%2==0){  //even difference
                    return jump;
                }
                else{
                    jump++;
                    sum+=jump;
                }
            }
        }
        return jump;
    }
};