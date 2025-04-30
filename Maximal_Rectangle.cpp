// // yh question sirf largest rectangle in histogram ka extension hai agr aapne wh question kr rkha hai to 
// // ise easily samjh sakte ho..

// // largest rectangle in histogram mai 1d hota hai aur usme height diya hota hai pr is question mai aapko
// // height nikalana hota hai jo ki 2d ko 1d mai convert mai krke krte ho by comulative add krke uske upr wale 1 ko ..
// // yha pe ek gaur krne wali baat yh hai ki agr 0 ho to app commulative add nhi kroge isko is trah se smjho ki bulding ki height 
// // jb base se hi ho ..base mai hi height 0 ho jayegi to bulding mai kya hwa mai rhegi..

// // height nikl jayegi cummulative add se pr aap dhyan rkhoge ki hr ek row by row kroge jisse sare possible area ko cover kr sko ..directly 2d ko 1d mai convert
// // total sum usk upr wale ko to hum sare area ko cover nhi kr payenge..
// // sare possible area ko cover krne ke liye row by row krna hoga..

// // ab height to nikl gya ab area nikalne ke liye width chahiye uske jo concept aapne largest reactangle in histogram mai use 
// // kiya tha whi use krna hai..
// // left mai kha tk bhaag skte ho as well hai right mai aur nsr[i]-nsl[i]-1.-1 krna jurrori hai to get the actual width..

// // ab aapke pas height aur widht bhi hai bs ho gya kaam hr possible area nikalo max se compare krte jao ..
// // aur jo max area mile use return kr de..

class Solution {
    public:
   // getting the next_Smaller_Element index
    vector<int> get_NSL(vector<int> heights){ 
        stack<int> st;
        int n = heights.size();
        vector<int> result(n);

        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            result[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return result;
    }
        // getting the next_Smaller_Element index
       vector<int> get_NSR(vector<int> heights){ 
        stack<int> st;
        int n = heights.size();
        vector<int> result(n);

        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            result[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return result;
    }

    int find_Max_Area(vector<int> heights){
        int n = heights.size();
        vector<int> width(n);
        int area =0;
        int max_Area =0;
        vector<int> next_smaller_left = get_NSL(heights);
        vector<int> next_smaller_right = get_NSR(heights);
        // height is caluculated only
        // we have to take care of the width which can accquired by using the formulae NSR[I]-NSL[I]-1;
        //doing -1 is compulsory remember that..
        for(int i = 0; i<n; i++){
            width[i] = next_smaller_right[i] - next_smaller_left[i] -1;
        }
        // now calculate the area..
        // remember one thing here also, we will take care of the maxArea but this area is of the row only.
        // and the maxArea that we are calculating in the calling function is taking care of the total maxArea which it recieves row by row..
        for(int i =0; i<n; i++){
            area = heights[i] * width[i];
            max_Area = max(area, max_Area);
        }
        return max_Area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) { 
        if(matrix.empty() || matrix[0].empty()) return 0;
        int n = matrix.size();  //row size
        int m = matrix[0].size(); //column size

        // for monitoring the maximum area for each time..
        int maxArea = 0;

        // phle ek heights ka array bna lete hai jo ki sare heights ko maintain krta rhega..aur initially 
        // uski value whi rhegi jo ki phle row ki rhegi aur kyuki wh char mai hum int mai krna pdega to directly copy nhi kr skte..
         vector<int> heights(m, 0);
        for(int i=0; i<m;i++){
            matrix[0][i] == '1' ? heights[i]=1: heights[i] = 0;
        }

        // for row 0 find the maxArea before only why i don't know.
        // because here we dont need to the cummulative sum..i think..
         maxArea = find_Max_Area(heights);

        // now doing it for row by row 
        for(int row =1; row<n; row++){
           for(int col =0; col<m; col++){
            if(matrix[row][col] == '1'){
                heights[col] = heights[col]+1;
            } 
            // as if it's value is 0 we can't do the cummulative sum for the height..kyuki building hwa mai thori rhegi..
            else
             heights[col] = 0;
           }
          // after finding the cummulative height we we send it to function which will return the max area for that
           //  heights of the row.
           maxArea = max(maxArea, find_Max_Area(heights));
        }
        return maxArea;
      
    }
};

// class Solution {
// public:
//     // Function to get the next smaller element to the left (NSL)
//     vector<int> get_NSL(vector<int>& heights) { 
//         stack<int> st;
//         int n = heights.size();
//         vector<int> result(n);

//         for(int i = 0; i < n; i++) {
//             while(!st.empty() && heights[st.top()] >= heights[i]) {
//                 st.pop();
//             }
//             result[i] = st.empty() ? -1 : st.top();
//             st.push(i);
//         }
//         return result;
//     }

//     // Function to get the next smaller element to the right (NSR)
//     vector<int> get_NSR(vector<int>& heights) { 
//         stack<int> st;
//         int n = heights.size();
//         vector<int> result(n);

//         for(int i = n-1; i >= 0; i--) {
//             while(!st.empty() && heights[st.top()] >= heights[i]) {
//                 st.pop();
//             }
//             result[i] = st.empty() ? n : st.top();
//             st.push(i);
//         }
//         return result;
//     }

//     // Function to find the maximum area in a histogram
//     int find_Max_Area(vector<int>& heights) {
//         int n = heights.size();
//         vector<int> next_smaller_left = get_NSL(heights);
//         vector<int> next_smaller_right = get_NSR(heights);
        
//         int max_Area = 0;
        
//         for(int i = 0; i < n; i++) {
//             int width = next_smaller_right[i] - next_smaller_left[i] - 1;
//             int area = heights[i] * width;
//             max_Area = max(area, max_Area);
//         }
//         return max_Area;
//     }

//     int maximalRectangle(vector<vector<char>>& matrix) {
//         if(matrix.empty() || matrix[0].empty()) return 0;
        
//         int n = matrix.size();     // number of rows
//         int m = matrix[0].size(); // number of columns
//         int maxArea = 0;

//         // Initialize heights array
//         vector<int> heights(m, 0);
        
//         for(int row = 0; row < n; row++) {
//             for(int col = 0; col < m; col++) {
//                 // Update the height: add 1 if current cell is '1', reset to 0 otherwise
//                 heights[col] = (matrix[row][col] == '1') ? heights[col] + 1 : 0;
//             }
//             // Calculate max area for current histogram
//             maxArea = max(maxArea, find_Max_Area(heights));
//         }
//         return maxArea;
//     }
// };