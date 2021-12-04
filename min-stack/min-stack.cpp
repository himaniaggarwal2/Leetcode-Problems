class MinStack {
public:
    stack<int> allData;
    stack<int> minData;
    MinStack() {
        
    }
    
    void push(int val) {
        allData.push(val);
        
        if(minData.empty() or val <= minData.top()){
            minData.push(val);
        }
    }
    
    void pop() {
        if(allData.empty()) return;
        else{
            int val = allData.top();
            allData.pop();
            if(val==minData.top()){
                minData.pop();
            }
        }
    }
    
    int top() {
        if(allData.empty()) return 0;
        else return allData.top();
    }
    
    int getMin() {
        if(minData.empty()) return 0;
        else return minData.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */