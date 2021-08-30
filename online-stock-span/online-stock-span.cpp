class StockSpanner {
public:
    vector<int> arr;
    stack<int> st;
    int i=-1;
    StockSpanner() {
        
    }
    
    int next(int price) {
        arr.push_back(price);
        i++;
        while(!st.empty() and arr[st.top()]<=price) st.pop();
        
        int top=st.empty()?-1:st.top();
        int x= i-top;
        st.push(i);
        return x;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 int i=-1;
    stack<int> s;
    
    vector<int> arr;
    StockSpanner() {}
    
    int next(int price) {
        arr.push_back(price);
        i++;
        while(!s.empty() && arr[s.top()]<=price)
            s.pop();
        int top=s.empty()?-1:s.top();
        int x=i-top;
        s.push(i);
        return x;
 */