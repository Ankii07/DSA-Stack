// 

#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        for (int asteroid : asteroids) {
            bool destroyed = false;
            
            while (!st.empty() && asteroid < 0 && st.top() > 0) { // Collision condition
                if (abs(st.top()) < abs(asteroid)) {
                    st.pop(); // Top asteroid is smaller, it gets destroyed
                    continue;
                } else if (abs(st.top()) == abs(asteroid)) {
                    st.pop(); // Both are equal, both get destroyed
                }
                
                destroyed = true;
                break;
            }
            
            if (!destroyed) {
                st.push(asteroid);
            }
        }
        
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; --i) {
            result[i] = st.top();
            st.pop();
        }
        
        return result;
    }
};
