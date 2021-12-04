class MyStack {
public:
    queue<int> mainQ,helperQ; 
    MyStack() {
       
    }
    
    void push(int x) {
        while(mainQ.size()>0){
            int q= mainQ.front();
            mainQ.pop();
            helperQ.push(q);
        }
        mainQ.push(x);
        while(helperQ.size()>0){
            int q=helperQ.front();
            helperQ.pop();
            mainQ.push(q);
        }
    }
    
    int pop() {
      if(mainQ.size()==0) return 0;
        else{
            int p=mainQ.front();
            mainQ.pop();
            return p;
        }
    }
    
    int top() {
        if(mainQ.size()==0) return 0;
        else
            return mainQ.front();
    }
    
    bool empty() {
        return mainQ.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */