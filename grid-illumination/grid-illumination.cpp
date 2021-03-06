class Solution {
public:
    
//         vector<int> ans;
//         unordered_map<int , int> rows,col,d1,d2;
//         unordered_map<int , int> cell_no;
//         long NN = (long)n;
        
//         for(int i=0;i<lamps.size();i++){
//             rows[lamps[i][0]]++;
//             col[lamps[i][1]]++;
//             d1[lamps[i][0]+lamps[i][1]]++;
//             d2[lamps[i][0]-lamps[i][1]]++;
//             cell_no[(NN*lamps[i][0])+lamps[i][1]]++;
//         }
        
//         vector<vector<int>> arr{{-1,-1},{-1,0},{0,-1},{1,0},{0,1},{-1,1},{1,-1},{1,1}};
//         for(int i=0;i<queries.size();i++){
            
//             int nr=queries[i][0];
//             int nc=queries[i][1];
            
//             bool flag=false;
            
//             for(int j=0;j<8;j++){
                
//                 if(cell_no.find(n*(nr+arr[j][0])+(nc+arr[j][1]))!=cell_no.end()){
                    
//                     if(flag==false) {
//                         ans.push_back(1);
//                         flag=true;
//                     }
                    
//                     int a=nr+arr[j][0];
//                     int b=nc+arr[j][1];
                    
//                     if(--rows[a]==0) rows.erase(a);
//                     if(--col[b]==0) col.erase(b);
//                     if(--d1[a+b]==0) d1.erase(a+b);
//                     if(--d2[a-b]==0) d2.erase(a-b);
//                     if(--cell_no[n*(nr+arr[j][0])+(nc+arr[j][1])]==0) cell_no.erase(n*(nr+arr[j][0])+(nc+arr[j][1])); 
                    
//                 }
//             }
//             if(flag==false){
//                 ans.push_back(0);
//             }
//         }
//        return ans; 
        vector<vector<int>> dir {{1, 0},{-1, 0},{0, 1},{0, -1},{1, 1},{-1, 1},{1, -1},{-1, -1},{0, 0}};
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<long int, bool> lamp;
        unordered_map<int, int> row, col, diag, antiDiag;
        for (int i = 0; i < lamps.size(); i++) {
            int x = lamps[i][0], y = lamps[i][1];
            if (lamp[x * (long)N + y])
                continue;
            lamp[x * (long)N + y] = true;
            row[x]++;
            col[y]++;
            diag[x + y]++;
            antiDiag[x - y]++;
        }
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int x = queries[i][0], y = queries[i][1];
            ans[i] = (row[x] or col[y] or diag[x + y] or antiDiag[x - y]) ? 1: 0;
            for (int d = 0; d < dir.size(); d++) {
                int r = x + dir[d][0];
                int c = y + dir[d][1];
                if (r >= 0 and c >= 0 and r < N and c < N and lamp[r * (long)N + c]) {
                    row[r]--;
                    col[c]--;
                    diag[r + c]--;
                    antiDiag[r - c]--;
                    lamp[r * (long)N + c] = !lamp[r * (long)N + c];
                }
            }
        }
        return ans;
    }
};
/*

*/