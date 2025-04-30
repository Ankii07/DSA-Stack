class MyQueue {
    public:
        // amotized means bhut baadi humare operation O(1) mai hi ho ja rha hai..
        // kbhi kbhi hi O(n) mai operation ho rhe hai;
        stack<int> input;
        stack<int> output;
        int peek_element=0;
    
        MyQueue() {
            
        }
        
        void push(int x) {
         if(input.empty())
          peek_element = x;
          input.push(x);
        }
        
        int pop() {
           if(output.empty()){
              while(!input.empty()){
                output.push(input.top());
                input.pop();
              }
           }
              int result = output.top();
              output.pop();
             return result;
           
        }
        
        int peek() {
            if(!output.empty()){
            int result1 = output.top();
             return result1;
           }
           else{
            //   while(input.empty()){
            //     output.push(input.top())
            //     input.top();
            //   }
            //   int reuslt = output.top();
            //   output.pop();
            //  return result;
            return peek_element;
           }
        }
        
        bool empty() {
            return (output.empty() && input.empty());
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