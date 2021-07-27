// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1#
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int k) {
                                                 
    int i=0,j=0;
    queue<int> q;
    vector<long long> ans;
    while(j<N){
        if(A[j]<0) q.push(A[j]);
        if(j-i+1<k){
            j++;
        }
        else if(j-i+1==k){
            if(q.size()==0) ans.push_back(0);
                
            else ans.push_back(q.front());
                
            if(A[i]<0) q.pop();
                
            i++;
            j++;
                
            }
        }
    return ans;
 }