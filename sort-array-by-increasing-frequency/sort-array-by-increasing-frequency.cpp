// typedef pair<int,int> ppi;
// struct comp{
//   bool operator()(ppi &a,ppi &b){
//       return a.second>b.second;
//   }  
// };

// class Solution {
// public:
//     vector<int> frequencySort(vector<int>& nums) {
//         int n=nums.size();
//         if(n==1) return {nums[0]};
        
//         vector<int> res;
//         unordered_map<int,int> mp;
        
//         for(auto curr : nums){
//             mp[curr]++;
//         }
    
//         priority_queue<ppi,vector<ppi>,greater<ppi> > minh;
//         for (auto x:mp){
//             minh.push({x.second,x.first});
//         }
        
//         while(minh.size()>0){
//             int freq=minh.top().first;
//             int ele=minh.top().second;
//             for(int i=0;i<freq;i++){
//                 res.push_back(ele);
//             }
//             minh.pop();
//         }
    
//     return res;
//     }
// };

class Solution {
public:
    
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        map<int,priority_queue<int>> pq;
        for(auto &x: nums)
            mp[x]++;
        for(auto &x : mp)
            pq[x.second].push(x.first);
        vector<int> v;
        for( auto &x: pq){
            int a = x.first;
            while(!x.second.empty()){
                while(a--)
                v.push_back(x.second.top());
                a = x.first;
                x.second.pop();
            }
        }
        return v;      
    }
};