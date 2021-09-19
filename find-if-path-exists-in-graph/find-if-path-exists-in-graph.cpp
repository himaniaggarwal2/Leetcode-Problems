class Solution {
public:
    void buildGraph(vector <int> adj[],vector<vector<int>>& edges){
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
    }
	
    void dfs(vector <int> adj[],int source,int target,bool visited[]){
        visited[source] = true;
        
        for(int v:adj[source]){
            if(visited[v] == false){
                dfs(adj,v,target,visited);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector <int> adj[n];
        buildGraph(adj,edges);
        bool visited[n];
        for(int i=0; i<n; i++)
            visited[i] = false;
        dfs(adj,start,end,visited);
        return visited[end];
    }
    
};