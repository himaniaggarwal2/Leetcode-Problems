#include <stdc++.h>
using namespace std;

class Graph{
public:
    map<int,bool> visited;
    map<int, list<int> > adj;

    void addEdge(int v, int w);
    void DFS(int v);
};

void Graph:: addEdge(int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph:: DFS(int v){
    visited[v]=true;
    cout<<v<<" ";
    list<int>::iterator it;

    for( it=adj[v].begin();it!=adj[v].end();it++){
        if(!visited[*it])
            DFS(*it);
    }
}

int main(){
    Graph g;
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.addEdge(4,5);
    g.addEdge(3,5);
    g.addEdge(3,6);
    g.addEdge(6,4);
    g.addEdge(6,7);
    g.addEdge(4,7);

    g.DFS(2);
}