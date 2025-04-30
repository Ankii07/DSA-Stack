class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            unordered_map<int, int> m;
            vector<int> result;
            int m1 = nums1.size();
            int n = nums2.size();
            int f =0;
            stack<int> st;
    
            for(int i=n-1; i>=0;i--){
               if(st.empty()){
                  m[nums2[i]] = -1;
                  st.push(nums2[i]);
               }
               else{
                  while(st.top()< nums2[i]){
                     st.pop();
                     if(st.empty()){
                      f=1;
                      break;
                     }
                  }
                  if(f == 1){
                    m[nums2[i]] = -1;
                    st.push(nums2[i]);
                    f=0;
                  }
                  else{
                    m[nums2[i]] = st.top();
                    st.push(nums2[i]);
                  }
               }
            }
          for(int i =0; i<m1; i++){
             result.push_back(m[nums1[i]]);
          }
           return result;
        }
    };