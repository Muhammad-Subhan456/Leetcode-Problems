class MyQueue {
    stack<int>st;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        this->st.push(x);
    }
    
    int pop() {
    if(this->st.empty()) return -1;
    stack<int>temp;
    while(this->st.size()>1){
        temp.push(st.top());
        st.pop();
    }
    int ele = st.top();
    this->st.pop();
    while(!temp.empty()){
        this->st.push(temp.top());
        temp.pop();
    }
    return ele;
    }
    
    int peek() {
    if(this->st.empty()) return -1;
    stack<int>temp;
    while(this->st.size()>1){
        temp.push(st.top());
        st.pop();
    }
    int ele = st.top();
    while(!temp.empty()){
        this->st.push(temp.top());
        temp.pop();
    }
    return ele;
    }
    
    bool empty() {
        return st.empty();
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