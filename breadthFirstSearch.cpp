#include <stdc++.h>
using namespace std;

class Graph{
    int v;
    list<int> *l;

public:
    Graph(int V){
        this->v=V;
        l= new list<int> [V];
    }
    void addEdge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void bfs(int src){
        bool *visited =  new bool[v] {0};
        queue<int> q;

        q.push(src);
        visited[src]=true;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int neighbor: l[node]){
                if(!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }
};

int main(){

    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(5,6);
    g.addEdge(4,5);
    g.addEdge(0,4);
    g.addEdge(3,4);
    g.addEdge(3,5);

    g.bfs(1);
    return 0;
}