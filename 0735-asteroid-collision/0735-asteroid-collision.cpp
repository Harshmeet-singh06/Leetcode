class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n = a.size();
        vector<int> ans;
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            if(!st.empty() && st.top() < 0 && a[i] > 0){
                while(!st.empty() && st.top() < 0 && abs(a[i]) > abs(st.top())){
                    st.pop();
                }         
            if(st.empty()){
                st.push(a[i]);
            }
            else if(st.top() < 0 && abs(st.top()) == abs(a[i])){
                st.pop();
            }
            else if(st.top() < 0 && abs(a[i]) < abs(st.top())){
                continue;
            }
            else{
            st.push(a[i]);
        }
        }
        else{
            st.push(a[i]);
        }
    }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};