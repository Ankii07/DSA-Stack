class Solution {
    public:
        //question related to the monotonic stack theory.. 
        vector<int> nextGreaterElements(vector<int>& nums) {
            int n = nums.size();
            vector<int> result;
            stack<int> st;
            for(int i =2*n-1; i>=0; i--){
                 int currentIndex = i%n;
                //  jb tk stack ka top chota hai current element se pop krte jayenge..
                 while(!st.empty() && st.top() <= nums[currentIndex]){
                     st.pop();
                 }
                //  result mai push krna tabhi start krenge jb i <n ho kyuki we are dealing with circular array..
                 if(i<n){
                    // agr stack empty hai to -1 push kr denge..
                    if(st.empty()){
                        result.push_back(-1);
                    }
                    // na to push krenge top of th stack..
                    else{
                        result.push_back(st.top());
                    }
                 }
                //  now putting the current index element in the stack so that we can compare it to the other elements as well..
                st.push(nums[currentIndex]);
            }
            reverse(result.begin(), result.end());
            return result;
        }
    };