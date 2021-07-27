// #include <bits/stdc++.h>
#include <stdc++.h>
using namespace std;
 
 int main(){
    int n;
    cin>>n;
    int nums[n];
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    priority_queue<int,vector<int>,greater<int> > pq;
    long h = 0;
        
        for(int i = 0 ;i < n; i++){
            pq.push(nums[i]);
            h += (long) nums[i];
            if(h < 0){
                h -= pq.top();
                pq.pop();
            }
        }
        cout<<pq.size();
    return pq.size();
}
/*
// int main(){
//     int n;
//     cin>>n;
//     vector<int> nums;
//     for(int i=0;i<n;i++){
//         int t;
//         cin>>t;
//         nums.push_back(t);
//     }
//     priority_queue<int,vector<int>,greater<int> > pq;
//     pq.push(nums[0]);
//     for(int i=1;i<nums.size();i++){
//         int topi=pq.top();
//         if(topi-nums[i]>=0){
//             pq.push(nums[i]);
//         }
//         else{
//             pq.pop();
//             pq.push(nums[i]);
//         }
//     }
//     // priority_queue<int,vector<int>,greater<int> > pq;
//     // int sum=0;
//     // for(int i=0;i<n;i++){
//     //     sum+=nums[i];
//     //     if(sum>=0) {
//     //         pq.push(nums[i]);
//     //     }
//     //     else{
//     //         sum-=nums[i];
//     //     }
//     // }
//     // while(!pq.empty()){
//     //     cout<<pq.top()<<endl;
//     //     pq.pop();
//     // }
//     cout<<pq.size();
//     return pq.size();
//     exit(0);
// }


// // #include <bits/stdc++.h>
// using namespace std;
 
*/