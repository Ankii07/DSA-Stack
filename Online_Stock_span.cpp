class StockSpanner {
    public:
        //for storing the values..
        stack<pair<int,int>> st;
        StockSpanner() {
            
        }
        
        int next(int price) {
            int span = 1; //the span value will always be 1 atleast for itself..
    
            while(!st.empty() && st.top().first <= price){
                span = span + st.top().second;
                st.pop();
            }
            st.push({price, span});
    
            return span;
        }
    };
    
    /**
     * Your StockSpanner object will be instantiated and called as such:
     * StockSpanner* obj = new StockSpanner();
     * int param_1 = obj->next(price);
     */