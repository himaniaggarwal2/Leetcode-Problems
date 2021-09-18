class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
               
        long nn=n; // making copy of original n
        
        if(nn < 0) nn=-1 * nn; // making the power positive
        
        while(nn!=0)
        {
         
            if(nn%2==0)
            {
                x=x*x;
                nn=nn/2;
            }
            else
            {
                ans=ans*x;
                nn=nn-1;
            }
            
        }
        
        if(n < 0) return  1.0/  ans;
        return ans;
    }
};