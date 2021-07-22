//https://practice.geeksforgeeks.org/problems/sum-of-elements-between-k1th-and-k2th-smallest-elements3133/1#

public:
    long long sumBetweenTwoKth( long long a[], long long n, long long k1, long long k2)
    {
        if(k2<k1){
            std::swap(k1,k2);
        }
        priority_queue<long long, vector<long long>, greater <long> > heap;
        for(int i=0;i<n;i++){
            heap.push(a[i]);
        }
        long long u=0;
        long long v=0;
        long long k=1;
        while(!heap.empty()){
            if(k1==k){
                u=heap.top();
                cout<<u<<endl;
            }
            if(k2==k){
                v=heap.top();
                cout<<v<<endl;
            }
            heap.pop();
            k++;
        }
        long long count=0;
        for(int i=0;i<n;i++){
            if(a[i]>u and a[i]<v){
                count+=a[i];
            }
        }
        return count;
    }