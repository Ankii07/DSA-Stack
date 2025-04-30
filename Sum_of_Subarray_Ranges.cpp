// yha pe catch yh hai ki sum of ranges ko is trah se treat kr skte hai ki
// sum of all the largest in the subarray - sum of all the smallest in the subarray
// to jaise sum of sub arrays minimum ko solve kiya tha usi trah se 
// sum of subarray maximum ko solve  krna hai aur dono difference se humara required answer aa jayega..

class Solution {
    public:
        
        long long subArrayRanges(vector<int>& nums) {
           int n = nums.size();
        long long sumMax = 0, sumMin = 0;
    
        // Finding the contribution of each element as maximum
        stack<int> stMax;
        vector<int> leftMax(n), rightMax(n);
    
        for (int i = 0; i < n; i++) {
            while (!stMax.empty() && nums[stMax.top()] < nums[i]) {
                stMax.pop();
            }
            leftMax[i] = stMax.empty() ? i + 1 : i - stMax.top();
            stMax.push(i);
        }
    
        while (!stMax.empty()) stMax.pop();
    
        for (int i = n - 1; i >= 0; i--) {
            while (!stMax.empty() && nums[stMax.top()] <= nums[i]) {
                stMax.pop();
            }
            rightMax[i] = stMax.empty() ? n - i : stMax.top() - i;
            stMax.push(i);
        }
    
        for (int i = 0; i < n; i++) {
            sumMax += (long long)nums[i] * leftMax[i] * rightMax[i];
        }
    
        // Finding the contribution of each element as minimum
        stack<int> stMin;
        vector<int> leftMin(n), rightMin(n);
    
        for (int i = 0; i < n; i++) {
            while (!stMin.empty() && nums[stMin.top()] > nums[i]) {
                stMin.pop();
            }
            leftMin[i] = stMin.empty() ? i + 1 : i - stMin.top();
            stMin.push(i);
        }
    
        while (!stMin.empty()) stMin.pop();
    
        for (int i = n - 1; i >= 0; i--) {
            while (!stMin.empty() && nums[stMin.top()] >= nums[i]) {
                stMin.pop();
            }
            rightMin[i] = stMin.empty() ? n - i : stMin.top() - i;
            stMin.push(i);
        }
    
        for (int i = 0; i < n; i++) {
            sumMin += (long long)nums[i] * leftMin[i] * rightMin[i];
        }
    
        return sumMax - sumMin;
            
        }
    };