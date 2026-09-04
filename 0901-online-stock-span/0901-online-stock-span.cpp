class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count = 1;
        if(st.empty() || (!st.empty() && st.top().first > price)){
            st.push({price,1});
            return 1;
        }
        int val = st.top().first;
        while(!st.empty() && st.top().first <= price){
            if(st.top().first <= val){
                count += st.top().second;
                st.pop();
                continue;
            }
            val = st.top().first;
            count += st.top().second;
            st.pop();
        }
        st.push({price,count});
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */