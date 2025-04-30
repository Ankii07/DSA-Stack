class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
         int n = nums.size();
         //kyuki hume front aur back dono se operation ke saath deal krna hai to hum use krenge deque..
          deque<int> dq;
        //   for storing the result
          vector<int> result;
        //   hum element ki jgh indexes ko store krenge ..jisse ki hum yh check kr paye ko woh window mai aayega yaa nhi..
          for(int i=0; i<n; i++){
             
            //  step1. check for the element comes in the window or not if not pop it..
            // aage se start krenge pop krna..
            if(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }
            // ab jo bhi elements bche hai yaani unke index wh sare window mai to lie krenge..
            // ab is window ka jo maximum element hoga usko front pe laayenge by deleting all the other smaller element..
            // kyuki wh humare answer pe effect nhi krega..
            // front pe laane se yh fayda hoga hume smaller element se compare nhi krega current element ko ..jisse ki complexity kam ho gi..
            // aur kuki window ke bahr ke element ko phle hi delete kr chuke hai to window ke bahr ka max hoga bhi to uska tension nhi lena hai ..
            // wh removed ho gya hoga..aur piche ke element ko store kr rhe hai to aage jo element aayega usse compare ho jayega..
            while(!dq.empty() && nums[i] > nums[dq.back()] ){
                dq.pop_back();
            }
    
            // ab current element ko push kr denge..for further comparision..
            dq.push_back(i);
    
            // aur ab answer aana kb start hoga jb..i >= k-1 ho jayege tabhi wh sbse phle wali window bn payi hogi..
            // aur push kreng front wale element ..aur kyuki hum indexes ko push kr rhe naaki element ko to iska dhyan rakhe..yha pe.
            if(i>=k-1){
             result.push_back(nums[dq.front()]);
            }
         } 
         return result;
        //  if it helps you in any way.. I will be glad..please give a like..if not.. it's ok..
        // best wishes..
        }
    };