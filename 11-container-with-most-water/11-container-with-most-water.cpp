class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int omax=0;
        while(i<j){
            int storage = (j-i)* std::min(height[i],height[j]);
            omax= std::max(omax,storage);
            
            if(height[i]>height[j]){
                j--;
            }else i++;
        }
        return omax;
    }
};