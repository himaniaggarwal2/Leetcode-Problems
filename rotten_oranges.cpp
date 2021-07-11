//https://leetcode.com/problems/rotting-oranges/
#include <stdc++.h>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int> > rottenOranges;
        int freshOranges=0;
        int minTime=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                
                if(grid[i][j]==2) rottenOranges.push({i,j});
                else if(grid[i][j]==1) freshOranges++;
            } 
        }
        while(!rottenOranges.empty()){
            int qSize=rottenOranges.size();
            
            for(int i=0;i<qSize;i++){
                auto [x,y]=rottenOranges.front();
                rottenOranges.pop();
                if(x>0 and grid[x-1][y]==1){
                    freshOranges--;
                    grid[x-1][y]=2;
                    rottenOranges.push({x-1,y});
                }
                if(y>0 and grid[x][y-1]==1){
                    freshOranges--;
                    grid[x][y-1]=2;
                    rottenOranges.push({x,y-1});
                }
                if(x<grid.size()-1 and grid[x+1][y]==1){
                    freshOranges--;
                    grid[x+1][y]=2;
                    rottenOranges.push({x+1,y});
                }
                if(y<grid[0].size()-1 and grid[x][y+1]==1){
                    freshOranges--;
                    grid[x][y+1]=2;
                    rottenOranges.push({x,y+1});
                }
            }
            if(!rottenOranges.empty()) minTime++;
        }
    return freshOranges == 0 ? minTime : -1;
    }
};