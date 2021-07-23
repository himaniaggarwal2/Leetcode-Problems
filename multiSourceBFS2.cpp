#include <stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0; i<n; i++)
int main(){
    int n,m;
    cin>>n>>m;

    int a[n][m],dist[n][m];
    queue<pair<int,int> > Q;

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    int i,j;
    fo(i,n){
        fo(j,m){
            cin>>a[i][j];
            dist[i][j]=INT_MAX;
            if(i==0 and a[i][j]){
                Q.push({i,j});
                dist[i][j]=0;
            }
        }
    }
    
    //now Simple MUlti SOurce BFS

    while(!Q.empty()){
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        // if we reach the last row in our matrix we will simply break out
        if(x == n-1){
            break;
        }
        for(int i=0; i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx>=0 and nx<n and ny>=0 and ny<m){
                if(dist[nx][ny]== INT_MAX and a[nx][ny]){ //cause we are trvaversing on those cells only which have 1 in it
                    Q.push({nx,ny});
                    dist[nx][ny] = dist[x][y] + 1;
                }
            }
        }
    }

    fo(i,n){
        fo(j,m){
            cout<<dist[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}