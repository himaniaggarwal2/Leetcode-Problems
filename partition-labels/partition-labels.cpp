class Solution {
public:
    vector<int> partitionLabels(string s) {
        int arr[26];
        memset(arr,-1,26);
        for(int i=0;i<s.size();i++){
            arr[s[i]-'a']=i;
        }
        
        int n=s.size();
        int partitionindex=0;
        int i=0;
        int j=0;
        vector<int> result;
        while(j<n){
            int val=s[j]-'a';
            partitionindex=std::max(partitionindex,arr[val]);
            if(j==partitionindex){
                result.push_back(j-i+1);
                i=partitionindex+1;
            }
            j++;
        }
        return result;
    }
};