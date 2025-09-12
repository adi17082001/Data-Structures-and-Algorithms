class MyQueue {
    stack<int> s1, s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.size() != 0){
            int x = s2.top();
            s2.pop();
            return x;
        }
        while(s1.size()){
            s2.push(s1.top());
            s1.pop();
        }
        int x = s2.top();
        s2.pop();
        return x;
    }
    
    int peek() {
        if(s2.size() != 0){
            return s2.top();
        }
        while(s1.size()){
            s2.push(s1.top());
            s1.pop();
        }
        return s2.top();
    }
    
    bool empty() {
        if(s1.size() + s2.size() == 0) return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
