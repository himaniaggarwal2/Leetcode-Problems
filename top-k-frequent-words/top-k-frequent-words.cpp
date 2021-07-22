typedef pair<int,string> ppi;
class Solution {
public:
    struct comp{
      bool operator()(ppi&a,ppi &b){
        return a.second>b.second;  
      };  
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
//         vector<string> res;
        
//         unordered_map<string,int> mp;
//         for(int i=0;i<words.size();i++){
//             mp[words[i]]++;
//         }
       
//         priority_queue<ppi,vector<ppi>,comp > pq;
        
//         for(auto &x:mp){
//             cout<<x.first<<" "<<x.second<<endl;
//             pq.push({x.second,x.first});
//             if(pq.size()>k){
//                  // cout<<pq.top().first<<" "<<pq.top().second<<endl;
//                 pq.pop();
//             }
//         }
//         // auto tp=pq;
//         // while(!tp.empty()){
//         //     cout<<tp.top().first<<" "<<tp.top().second<<endl;
//         //     tp.pop();
//         // }
//         while(!pq.empty()){
//             res.push_back(pq.top().second);
//             pq.pop();
//         }
//         return res;
        vector<string> res;
    map<string, int> wordMap;
    map<int, vector<string>> countMap; 
    
    for (auto w : words) {
        wordMap[w]++;
    }
    
    for (auto it : wordMap) {
        int count = it.second;
        countMap[count].push_back(it.first);
    }
    
    for (auto it=countMap.rbegin(); it != countMap.rend(); ++it) {
        vector<string> curr = it->second;
        sort(curr.begin(), curr.end());
        for (auto s : curr) {
            res.push_back(s);
            k--;
            if (k==0) return res;
        }
    }
    
    // the code should never reach in here
    return res;
    }
};