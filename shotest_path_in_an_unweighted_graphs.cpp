#include <stdc++.h>
using namespace std;

class Graph{
    
    vector<int> adj;//adjacent
    
    public:
    void addEdge(int src,int dest){
        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }
    bool bfs(int src, int dest){
        std::map<int,bool> visited;
        std::queue<int> q;
        
        q.push(src);
        visited[src]=true;

        while(!q.empty()){ 
            int u=q.front();
            q.pop();
            for(int neighbor : adj[u]){
                if(!visited[neighbor]){
                    q.push(neighbor);
                    visited[neighbor]=true;
                }
            }
        }
    }
}

int main(){

}