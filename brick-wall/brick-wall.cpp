class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> mp;
        int maxi=0;
        int size_of_wall;
        for(int i=0;i<wall.size();i++){
            int prep=0;
            for(int j=0;j<wall[i].size();j++){
                prep+=wall[i][j];
                mp[prep]++;
            }
            size_of_wall=prep;
        }
        if(size_of_wall==1) return wall.size();
        else if(size_of_wall>1){
            for(auto it=mp.begin();it!=mp.end();it++){
                if(it->first!=size_of_wall){
                    maxi=std::max(it->second,maxi);
                }
            }
        }
        return wall.size()-maxi;
    }
};
/*
for(int i=1;i<size_of_wall;i++){
                if(mp.find(i)!=mp.end())
                    maxi=std::max(mp.find(i)->second,maxi);
            }
*/