// class MinStack {
// public:
//     // the problem which was on the brute force approach was we were dealing with 2n space complexcity..
//     // as we were using pair to store the minimum with current value..
//     // now if we want to get rid off that extra space we have to stop using the pair ..
//     // now if we can't use pair ..but we need to track the series of minimum which we have encounter along the way..
//     // to do that we will take the help of a mathematical formulae which will enable to us to do that..which is 2*val-current_minimum 
//     // will be stored at the top of stack when there will be change in the minimum, which will help us to know that here the minimum was changed..
//     // and as we are poping out this value the current minimum should be restored to the previous minimum which can be done by reversing the mathematical formula
//     // 2*current_minimum - value at the top of stack..

//     // and at the time getting the top we can check that if the current value is less than current min that means it is the modified value
//     // so we have to return the original value by reversing the formulae which we had used while storing that value..

//     //minimum will always the current minimum only..

//     stack<int> st;
//     int current_min;

//     MinStack() {
        
//     }
    
//     void push(int val) {
//         if(st.empty()){
//             st.push(val);
//             current_min= val;
//         }else{
//             if(val> current_min){
//                 st.push(val);
//             }
//             else{
//                 st.push(2*val - current_min);
//                 current_min = val;
//             }
//         }
//     }
    
//     void pop() {
//         if(st.empty()){
//             return;
//         }
//         else{
//             int val = st.top();
//             st.pop();
//             // agr value less than current min hai iska mtlb yha pe minimum update hua tha, isilye 
//             // hume current to restore krna hoga previous minimum pe...
//             if(val < current_min){
//               current_min = 2*current_min - val;
//             }
//         }
//     }
    
//     int top() {
//         if(st.empty())
//          return -1;
//         int val = st.top();
//         if(val < current_min){
//             val = 2* current_min - val;
//         }
//         return val;
//     }
    
//     int getMin() {
//         return current_min;
//     }
// };

// /**
//  * Your MinStack object will be instantiated and called as such:
//  * MinStack* obj = new MinStack();
//  * obj->push(val);
//  * obj->pop();
//  * int param_3 = obj->top();
//  * int param_4 = obj->getMin();
//  */

class MinStack {
    public:
        stack<long long> st; // Use long long to prevent overflow
        long long current_min; // Store current minimum as long long
    
        MinStack() {}
    
        void push(int val) {
            if (st.empty()) {
                st.push((long long)val);
                current_min = val;
            } else {
                if (val > current_min) {
                    st.push((long long)val);
                } else {
                    st.push(2LL * val - current_min); // Use long long for calculation
                    current_min = val;
                }
            }
        }
    
        void pop() {
            if (st.empty()) {
                return;
            }
            long long val = st.top();
            st.pop();
            if (val < current_min) {
                current_min = 2LL * current_min - val; // Restore previous minimum
            }
        }
    
        int top() {
            if (st.empty()) {
                return -1;
            }
            long long val = st.top();
            if (val < current_min) {
                return (int)current_min; // Original value when modified
            }
            return (int)val; // Cast back to int
        }
    
        int getMin() {
            return (int)current_min; // Cast back to int
        }
    };
    