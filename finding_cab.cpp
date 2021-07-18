//k largest

//https://practice.geeksforgeeks.org/problems/k-largest-elements3736/1#
class Solution
{
    public:
    //Function to return k largest elements from an array.
    vector<int> kLargest(int arr[], int n, int k)
    {
        priority_queue<int,vector<int>,greater<int>> heap;
        
        for(int i=0;i<k;i++){
            heap.push(arr[i]);
        }
        for(int i=k;i<n;i++){
            if(arr[i]>heap.top()){
                heap.pop();
                heap.push(arr[i]);
            }
        }
        vector<int> res;
        while(!heap.empty()){
            res.push_back(heap.top());
            heap.pop();
        }
        std::reverse(res.begin(),res.end());
        return res;
    }
};