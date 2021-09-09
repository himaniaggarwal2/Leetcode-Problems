class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        sort(intervals.begin(), intervals.end()); 
        for (auto& interval : intervals) {
            if (ret.empty() || ret.back()[1] < interval[0]) {
                ret.push_back(interval);
            } else {
                ret.back()[1] = max(ret.back()[1], interval[1]);
            }
        }

        return ret;
    }
//         vector<vector<int>> intervals=interval;
//         int n=intervals.size();
//         vector<vector<int>> result(n);
        
//         std::sort(intervals.begin(),intervals.end());
//         int i=0,j=1;
        
//         while(j<n and i<n){
//             int start=0;
//             int end=0;
//             if(intervals[i][1]>=intervals[j][0]){
//                     start=intervals[i][0];
//                     end=intervals[j][1];
//                     j++;
                
//             }
//             else if(intervals[i][1]<intervals[j][0]){
//                 start=intervals[i][0];
//                 end=intervals[i][1];
//                 i++;
//             }
//             result[start].push_back(end);
//         }
//         return intervals;
    // }
};