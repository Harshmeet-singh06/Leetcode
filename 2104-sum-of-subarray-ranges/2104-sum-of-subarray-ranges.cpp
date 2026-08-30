class Solution {
public:
    vector<int> next_greater(vector<int>& a){
        int n = a.size();
        stack<int> st;
        vector<int> greater(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && a[st.top()] > a[i]){
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
    vector<int> prev_greater(vector<int>& a){
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
    long long sumSubarrayMins(vector<int>& a) {
        int n = a.size();
        vector<int> nge = next_greater(a);
        vector<int> pge = prev_greater(a);
        long long total = 0;
        for(int i=0;i<n;i++){
            int left = i - pge[i];
            int right = nge[i] - i;
            total = (total + (left * right * 1LL * a[i]));
        }
        return total;
    }
    vector<int> next_smaller(vector<int>& a){
        int n = a.size();
        stack<int> st;
        vector<int> greater(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && a[st.top()] < a[i]){
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
            while(!st.empty() && a[st.top()] <= a[i]){
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
    long long sumSubarrayMaxs(vector<int>& a) {
        int n = a.size();
        vector<int> nge = next_smaller(a);
        vector<int> pge = prev_smaller(a);
        long long total = 0;
        for(int i=0;i<n;i++){
            int left = i - pge[i];
            int right = nge[i] - i;
            total = (total + (left * right * 1LL * a[i])) ;
        }
        return total;
    }
    long long subArrayRanges(vector<int>& a) {
        long long total = sumSubarrayMaxs(a) - sumSubarrayMins(a);
        return total;
    }
};