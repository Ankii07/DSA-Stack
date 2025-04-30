class Solution {
    public:
    
        // yha pe ek catch yh hai ki ek smallest number paane ke liye hume yh kosis krna hai ki 
        // hum required numbder ko increasing order mai rakhe..
        // aur ek specific direction mai jaa rhe hai jo ki increasing hai iska matlb yh monotonic stack ka question hai..
         
        // aur dusra point gaur krne wali yh hai ki jb bhi delete krna hoga hum try krenge significant position wale number 
        // ko krenge kyuki hume smallest number chahiye..
    
        string removeKdigits(string num, int k) {
           
            if(num.size() == k) return "0";
             
            //  string can act like stack only so we can do it using stack only..
            string result= "";
    
            for(int i=0; i<num.size();i++){
                // k>0 means that there is number of elements left to be deleted if all the required number got deleted
                // we will push all the left num as it is 
                while(result.length() > 0 && result.back() > num[i] && k> 0 ){
                    result.pop_back();
                    k--;
                }
                //  yha pe condition lga kr hum yh case handle kr le rhe ki prefix mai 0 aaye to use push nhi kreng..
                if(result.length() > 0 || num[i]!='0'){
                    result.push_back(num[i]);
                }
            }
    
            // managing the edge case that if the number are sorted
            while(result.length() >0 && k>0){
                 result.pop_back();
                    k--;
            }
             if(result == "") return "0";
            return result;    
        }
    };