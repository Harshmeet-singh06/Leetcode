class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0){
            return 0;
        }
        unordered_map<char,int> mpp;
        int l = 0;
        int r = 0;
        int len = 0;
        while(r < n){
            if(mpp.find(s[r]) == mpp.end()){
                mpp[s[r]] = r;
            }
            else{
                l = max(l,mpp[s[r]] + 1);
                mpp[s[r]] = r;
            }
            len = max(len,r-l+1);
            r++;
        }
        return len;
    }
};