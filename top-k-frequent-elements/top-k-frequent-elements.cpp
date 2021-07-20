typedef pair<int,int> ppi;
struct comp{
    bool operator()(pair<int,int>&a,pair<int,int>&b){
    return a.second < b.second;
    };
};
class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1) return {nums[0]};
        
        vector<int>res;
        unordered_map<int,int>mp;

        for(auto i:nums)
            mp[i]++;

        //Syntax for when we are using maps or sets within the priority_queue
        priority_queue<ppi,vector<ppi>,comp> pq(mp.begin(),mp.end());
        while(k>0){
            res.push_back(pq.top().first);
            pq.pop();
            k--;
        }
        return res;
    }
};
