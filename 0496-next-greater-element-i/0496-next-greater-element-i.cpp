class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        stack<int> st;
        unordered_map<int,int> mpp;
        for(int i=m-1;i>=0;i--){
            while(!st.empty() && st.top() <= b[i]){
                st.pop();
            }
            if(st.empty()){
                // st.push(a[i]);
                mpp[b[i]] = -1;
            }
            else{
                mpp[b[i]] = st.top();
            }
            st.push(b[i]);
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            ans.push_back(mpp[a[i]]);
        }
        return ans;
    }
};