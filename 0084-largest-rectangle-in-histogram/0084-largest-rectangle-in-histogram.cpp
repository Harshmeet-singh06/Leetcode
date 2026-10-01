class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        int n = a.size();
        stack<int> st;
        int area = 0;   
        for(int i=0;i<n;i++){
            while(!st.empty() && a[st.top()] > a[i]){
                int element = a[st.top()];
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                area = max(area,(nse - pse - 1) * element);
            }
            st.push(i);
        }
        while(!st.empty()){
            int element = a[st.top()];
            st.pop();
            int nse = n;
            int pse = st.empty() ? -1 : st.top();
            area = max(area,(nse - pse -1) * element);
        }
        return area;
    }
};