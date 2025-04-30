// are khuch nhi isme hard jaisa bs tag de diya hai hard ka
// phli baat koi bhi building tbhi water ko trap rkh skti hai jb ki usse bda ho ya uske barabar ho right mai bhi
// aur left mai jo ki boundary ka kaam kregi water ko log rakhne ke liye..

// yha pe ek aur cheez yh hai ki boundary to dono traf ki max hogi pr kon sa max decide krega ki itna water 
// logged hoga yh decided krega ki konsa max chota hai left max ya right max , kyuki jo chota max hai use jada height ki water to flow ho jeyge..

// ek aur catch hai ki jitni building ki height hogi wh to minus krna hoga ,,usko is trah se samjh skte ho ki bartan ka jo base ho bhut mota
// to toatal water logged ke bartan ki base ki height ko minus krna hoga..

// bs ho gya kaam aise hi hr bulding water trap mai kitna contribute kregi wh nikal kr sare ko add kr dena hai...aur 
// sb add kr denge to total volume water ko nikalne ke liye..

// yha pe jo mai galti kr rha tha yha pe next grater element ke sath deal nhi krna blki uske left ya right mai 
// sabse bdi building kon hai uske sath deal krna tha naki sabse pass ki max height wali building se..is cheez ka dhyan rakhe..


// class Solution {
// public:
//     int trap(vector<int>& height) {
        
//         int n = height.size();
//         vector<int> left_max(n,-1);
//         vector<int> right_max(n,-1);
//         stack<int> st;
//         int total_water =0;
//     // array containing the left max for all the element..
//         for(int i =0; i<n; i++){
//             while(!st.empty() && st.top() <= height[i]){
//                 st.pop();
//             }
           
//             if(st.empty()) left_max[i]=-1;

//             else left_max[i]=st.top();
//             //   cout <<left_max[i]<<" ";
//             st.push(height[i]);
//         }
//         // clearing the stack
//         while(!st.empty()){
//             st.pop();
//         }
//     // array containing the right max for all the element..
//     for(int i=n-1; i>=0; i--){
//         while(!st.empty() && st.top()<=height[i]){
//             st.pop();
//         }
//         if(st.empty()) right_max[i] =-1;
//         else right_max[i] =st.top();
//         st.push(height[i]);
//     }

//        for(int i =0; i<n;i++){
//           cout<<left_max[i]<<"i ";
        
//        }
//        cout<<"\n";
//        for(int j =n-1; j>=0;j--){
//           cout<<right_max[j]<<"j ";
        
//        }
     
//      return 0;
       

//     }
// };


class Solution {
    public:
        int trap(vector<int>& height) {
            
            int n = height.size();
            vector<int> left_max(n,-1);
            vector<int> right_max(n,-1);
            // stack<int> st;/
            int total_water =0;
        // array containing the left max for all the element..
         left_max[0] = height[0];
         for(int i=1; i<n;i++){
            left_max[i] = max(left_max[i-1],height[i]);
         }
    
         right_max[n-1] = height[n-1];
         for(int i=n-2; i>=0;i--){
            right_max[i] = max(right_max[i+1],height[i]);
         }
    
         for(int i=0; i<n;i++){
            total_water+=min(left_max[i],right_max[i])-height[i];
         }
    
         return total_water;
    
    
        }
    };