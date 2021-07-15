#include <stdc++.h>
using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
vector<int> bool;
void floodfill(int i,int j, vector<vector<int>>& grid,int n, int m,int color){
    grid[i][j]=color;
    visited[i][j]=1;
    for(int k=0;k<4;k++){
        int nx=i+dx[k];
        
        int ny=j+dy[k];
        if(nx>=0 and ny>=0 and nx<n and ny<m ){
            if(grid[nx][ny]==1 and !visited[nx][ny]){
                floodfill(nx,ny,grid,n,m,color);
            }
        }
    } 
}
int numIslands(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    int total_count=0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 and !visited[i][j]){
                // cout<<"hello";
                floodfill(i,j,grid,n,m,total_count);
                total_count++;
            }
        }
    }
        for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               cout<<grid[i][j]<<" ";
           }cout<<"\n";
        }
    return total_count;
}
