class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int> > res;
        priority_queue<pair<float, int>> pq;
        for(int i=0;i<points.size();i++){
            float euclidist= sqrt(points[i][0]*points[i][0] + points[i][1]*points[i][1]);
            pq.push({euclidist,i});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            res.push_back(points[pq.top().second]);
            pq.pop();
        }
        return res;
    }
};