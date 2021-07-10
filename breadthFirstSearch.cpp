#include <stdc++.h>
using namespace std;

template <typename T>

class Graph{
    map<T,list<T> > l;

public:
    void addEdge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void bfs(T, int src){
        map<T, int> visited;
        queue<T> q;

        q.push(src);
        visited[src]=true;

        while(!q.empty()){
            T node = q.front();
            q.pop();

            for(int neighbor: l[node]){
                if(!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }
}