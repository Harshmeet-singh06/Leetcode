class Solution {
public:
    string removeKdigits(string s, int k) {
        string st;

        for(char c : s) {
            while(!st.empty() && k > 0 && st.back() > c) {
                st.pop_back();
                k--;
            }
            st.push_back(c);
        }
        while(k > 0) {
            st.pop_back();
            k--;
        }
        int i = 0;
        while(i < st.size() && st[i] == '0') {
            i++;
        }
        if(i == st.size())
            return "0";
        return st.substr(i);
    }
};