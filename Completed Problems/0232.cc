class MyQueue {
    
private: 
    // use two stacks and shift the values between tehm each time someone pushes onto the queue so we can put a value at the bottom!
    stack<int>* s1;
    stack<int>* s2;
    
    stack<int>* currentStack;
    
    // moves all values between stacks
    void switchCurrentStack() {
        stack<int>* otherStack = currentStack == s1 ? s2 : s1;
        
        while (!currentStack->empty()) {
            otherStack->push(currentStack->top());
            currentStack->pop();
        }
        
        // update currentStack
        currentStack = otherStack;
    }
    
public:
    MyQueue() {
        s1 = new stack<int>;
        s2 = new stack<int>;
        currentStack = s1;
    }
    
    void push(int x) {
        stack<int>* startingStack = currentStack;
        
        switchCurrentStack();
        startingStack->push(x);
        switchCurrentStack();
    }
    
    int pop() {
        int top = currentStack->top();
        currentStack->pop();
        return top;
    }
    
    int peek() {
        return currentStack->top();
    }
    
    bool empty() {
        return currentStack->empty();
    }
    
    // deconstructor (unimplemented) deletes stacks s1, s2
};


/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */