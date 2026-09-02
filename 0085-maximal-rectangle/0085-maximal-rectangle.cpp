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
    int maximalRectangle(vector<vector<char>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>> psum(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=0;j<m;j++){
                if(a[i][j] == '1'){
                    psum[i][j] = (i == 0 ? 0 : psum[i-1][j]) + 1;
                }
                else{
                    psum[i][j] = 0;
                }
            }
        }
        int area = 0;
        for(int i=0;i<n;i++){
            area = max(area,largestRectangleArea(psum[i]));
        }
        return area;
    }
};