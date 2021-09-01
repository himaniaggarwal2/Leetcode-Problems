class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int i=0;
        int j=people.size()-1;
        std::sort(people.begin(),people.end());
        int count=0;
        while(i<=j){
            int sum=people[i]+people[j];
            if(sum<=limit){
                count++;
                i++;
                j--;
            }
            else if(sum>limit){
                count++;
                j--;
            }
        }
        return count;
    }
};
/*
int numRescueBoats(vector<int>& people, int limit) {
        int i=0,j=0;
        int n=people.size();
        bool visited[n];
        memset(visited,false,n);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                visited[i]=true;
                int rebel=count;
                for(int j=i;j<n;j++){
                    if(!visited[j] and limit-people[i]==people[j]){
                        rebel++;
                        visited[j]=true;
                    }
                }
                if(rebel==count) count++;
                else count=rebel;
            }
        }
        return count;
    }
*/