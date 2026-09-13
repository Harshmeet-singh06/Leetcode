class Solution {
public:
    vector<int> next_smaller(vector<int>& a){
        int n = a.size();
        stack<int> st;
        vector<int> greater(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && a[st.top()] >= a[i]){
                st.pop();
            }
            if(st.empty()){
                greater[i] = n;
            }
            else{
                greater[i] = st.top();
            }
            st.push(i);
        }
        return greater;
    }
    vector<int> prev_smaller(vector<int>& a){
        int n = a.size();
        stack<int> st;
        vector<int> greater(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && a[st.top()] >= a[i]){
                st.pop();
            }
            if(st.empty()){
                greater[i] = -1;
            }
            else{
                greater[i] = st.top();
            }
            st.push(i);
        }
        return greater;
    }
    int largestRectangleArea(vector<int>& a) {
        int n = a.size();
        vector<int> nse = next_smaller(a);
        vector<int> pse = prev_smaller(a);
        int area = 0;
        for(int i=0;i<n;i++){
            int left = pse[i];
            int right = nse[i];
            int value = (right - left - 1) * a[i];
            area = max(area,value);
        }
        return area;
    }
};