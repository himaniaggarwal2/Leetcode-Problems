// https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1#

class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
       priority_queue<long long,vector<long long>,greater<long long> > heap;
       
       for(int i=0;i<n;i++){
           heap.push(arr[i]);
       }
       if(heap.size()==1) return 0;
       long long total_count=0;
       while(!heap.empty()){
           if(heap.size()>=2){
               long long u=heap.top();
               heap.pop();
               long long v=heap.top();
               heap.pop();
               heap.push(u+v);
               total_count+=(u+v);
           }
          else if(heap.size()==1){
            
              heap.pop();
          }
        }
        return total_count;
    }
};