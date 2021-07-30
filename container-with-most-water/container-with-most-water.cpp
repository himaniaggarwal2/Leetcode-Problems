class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int stage;
        int omax=INT_MIN;
        while(i<j){
            
            int storage=(j-i)*std::min(height[i],height[j]);
            omax=std::max(storage,omax);
            
            if(height[i]<height[j])
                i++;
            else{
                j--;
            }
        }
        return (omax,stage);
    }
};
/*
int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int stage;
        int mx=0;
        while(i!=j){
            if(height[i]>height[j]){
                stage=height[i]*(j-i);
                j--;
            }
            else{
                stage=height[j]*(j-i);
                i++;
            }
            mx=std::max(mx,stage);
        }
        
        return mx;
    }
*/