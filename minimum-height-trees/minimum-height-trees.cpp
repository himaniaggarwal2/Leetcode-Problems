class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> res;
        if(n==0) return res;
        if(n==1) {
            res.push_back(0);
            return res;
        }
        
        vector<int> degree(n,0); //hold degree for the nodes
        vector<vector<int> > adj(n);//adjacency list
        
//         now putting all the values in degree and adjacency list
        for(auto &e: edges){
            degree[e[0]]++;
            degree[e[1]]++;
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
//         creating a queue so as to perform a bfs
        queue<int> q;
        for(int i=0;i<n;i++){
            if(degree[i]==1){
//                 if we have any value with degree then we push it to the queue
                q.push(i);
            }
        }
        
//         after that is done we will looping through till it our nodes are greater than 2
        while(n>2){
            int size=q.size();
//             then we decrement this size by n because as these many nodes are not eligible to be part of minimum heighted tree root
            n-=size;
//             iterating till size is zero
            while(size-->0){
                int v = q.front();
                q.pop();
                for(int i:adj[v]){
                    degree[i]--;
                    if(degree[i]==1) q.push(i);
                }
            } 
        }
        int size=q.size();
        while(size--){
            int top=q.front();
            q.pop();
            res.push_back(top);
        }
        return res;
    }
};