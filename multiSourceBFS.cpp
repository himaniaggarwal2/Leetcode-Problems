#include <stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<n;i++)

int main(){
    int n,m;
    cin>>n>>m;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};

    int a[n][m], dist[n][m];
    queue<pair<int,int> > q;
    int i,j;

    fo(i,n){
        fo(j,m){
            cin>>a[i][j];
            dist[i][j]= INT_MAX;
            if(a[i][j]){
                q.push({i,j});
                dist[i][j]=0;
            }
        }
    }

    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        int k;
        fo(k,4){
            int nx=x+dx[k];
            int ny=y+dy[k];
            if(nx>=0 and ny>=0 and nx<n and ny<m){
                if(dist[i][j] == INT_MAX){
                    q.push({nx,ny});
                    dist[nx][ny]= dist[x][y]+1;
                }
            }
        }
    }

    fo(i,n){
        fo(j,m){
            cout<<dist[i][j]<<" ";
        }cout<<"\n";
    }

    return 0;
}