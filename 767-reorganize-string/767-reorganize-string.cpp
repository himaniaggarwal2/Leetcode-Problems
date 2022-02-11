typedef pair<int, int> ppi;
class Solution {
public:
    string reorganizeString(string s) {
        map<int, int> mp;
        for (char ch : s) mp[ch]++;
        
        priority_queue<ppi> pq;
        for (auto p : mp)
            pq.push({p.second, p.first});
        
        string ans;
        ppi block = pq.top();
        pq.pop();
        ans+=block.second;
        block.first--;
        while(pq.size()>0){
            ppi temp = pq.top();
            pq.pop();
            ans+=temp.second;
            temp.first--;
            if(block.first>0){
                pq.push(block);
            }
            block=temp;
        }
        if(block.first>0){
            return "";
        }
        return ans;
    }
};