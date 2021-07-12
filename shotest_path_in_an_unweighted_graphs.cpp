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

    void bfs(int src,int dest){
        bool *visited =  new bool[v] {0};
        int *dist = new int[v]{0};
        int *parent = new int[v];
        queue<int> q;

        memset(parent, -1,v);
        q.push(src);
        visited[src]=true;
        parent[src]=src;
        dist[src]=0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int neighbor: l[node]){
                if(!visited[neighbor]) {
                    q.push(neighbor);
                    parent[neighbor]=node;
                    dist[neighbor]=dist[node]+1;
                    visited[neighbor] = true;
                }
            }
        }
        //print the shortest path
        for(int i=0;i<v;i++){
            cout<<"Shortest distance to "<<i<<" is "<<dist[i]<<endl;
        }

        //print the path from source to destination
        if(dest!=-1){
            int temp=dest;
            while(temp!=src){
                cout<<temp<<"-- ";
                temp=parent[temp];

            }
            cout<<src<<endl;
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

    g.bfs(1,6);
    return 0;
}

// #include <stdc++.h>
// using namespace std;

// class Graph{
    
//     vector<vector<int> > adj;//adjacent
//     int v;

// public:
//     Graph(int V){
//         this->v = V;
//     }
//     void addEdge(int src,int dest){
//         adj[src].push_back(dest);
//         adj[dest].push_back(src);
//     }
//     bool bfs(int src, int dest){
//         std::map<int,bool> visited;
//         std::queue<int> q;
//         vector<int> pred; // predecessor
//         vector<int> dist; // distance

//         q.push(src);
//         visited[src]=true;
//         dist[src]=0;

//         while(!q.empty()){ 
//             int u=q.front();
//             q.pop();
//             for(int neighbor : adj[u]){
//                 if(!visited[neighbor]){
//                     q.push(neighbor);
//                     dist[neighbor]=dist[u]+1;
//                     pred[neighbor]=u;
//                     visited[neighbor]=true;

//                     if(neighbor == dest) return true;
//                 }
//             }
//         }
//         return false;
//     }
// };

// int main(){

//     Graph g(6);
//     g.addEdge(1,2);
//     g.addEdge(1,4);
//     g.addEdge(1,3);
//     g.addEdge(2,4);
//     g.addEdge(2,3);
//     g.addEdge(3,4);

//     cout<<g.bfs(2,4);
// }
