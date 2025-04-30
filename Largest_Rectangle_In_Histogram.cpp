class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            // yh question previous smaller element aur next smaller element ka use krke krenge..
            // yha pe catch yh hai ki ek reactangle ke width ko hum wha tk stretch kr skte hai jb tak uske left mai
            // use chota koi number nhi aa jata aur right mai use koi chota nhi aa jata..
    
            // to humara kaam yh hoga hr ek element ke liye uska previous smaller element aur next smaller elememt ke index
            // ka track rakhe jisse ki hum uska area nikal paaye aur max se compare krke maximum area nikal paaye..
    
            // aap is cheez ko is trah visuallize kr skte ho ki maan lo aap ko kha hai building ke terrace jitni lambe se lambi daur laga skte ho lagao..
            // agr adajacent building ke hight current building ke height se jada hui to aap aage ki run ko continue kr skte let say khidkiyo se ghush kr building ko pass kr li..
            // pr agr bulding ki hight current building ke height se chhoti aa gyi to aapko apna run whi rokna pdega uske aage nhi badh skte..
            // that's how i tried to visualize..
    
            int l = heights.size();
            stack<int> st;
             int prev_smaller[l];
             int next_smaller[l];
            int maxi =0;
            // for previous smaller index..
            for(int i =0; i<l; i++){
                // jab tk stack empty nhi ho jata ya st.top() , current element se chota nhi aa jata pop krte jao..
                while(!st.empty() && heights[st.top()]>= heights[i]){
                    st.pop();
                }
                // agr pop krte krte ek to yh ho skta hai stack pura empty ho jaye..
                // stack pura empty ho gya iska mtlb element se koi bhi chhota nhi hai uske right mai iska matlb pura 0 index
                // tk stretch kr skte hai.. to uske prev element mai l-1 index push kr denge..
                if(st.empty()) prev_smaller[i]= 0;
                // st.empty nhi hua hoga iska mtlb koi smaller element mil gya hoga..
                // aur boundary us element ke index se ek jada rakhenge aur prev mai aur ek km agr wh next mai hai.
                // aur yh dhyan rkhe ke hum index maintain kr rhe na ki elements..
                else prev_smaller[i] =st.top()+1;
                // push the index of the element..
                st.push(i);
            }
        
    
        //clearing the stack so that it can used for next smaller element..
        while(!st.empty()) st.pop();
        // for next smaller element..
        for(int i =l-1; i>=0; i--){
              while(!st.empty() && heights[st.top()]>= heights[i]){
                    st.pop();
                }
                 if(st.empty()) next_smaller[i]=l-1;
                //yha pe boundary ek km set krenege..
                else 
                  next_smaller[i] = st.top()-1;
                st.push(i);
        }
        // calculating the area for each and getting the max out of it..
        for(int i =0; i<l; i++){
            // +1 to tackle 0 based indexing..
           maxi = max((next_smaller[i] - prev_smaller[i]+1)*heights[i], maxi);
        }
       
        return maxi;
    }
    
    };