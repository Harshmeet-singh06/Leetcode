class Solution {
public:
    bool wildcard(int i,int j,string& s,string& t,vector<vector<int>>& dp){
        if(i < 0 && j < 0){
            return true;
        }
        if(i >= 0 && j < 0){
            return false;
        }
        if(i < 0 && j >= 0){
            for(int ii=0;ii<=j;ii++){
                if(t[ii] != '*'){
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i] == t[j] || t[j] == '?'){
            return dp[i][j] = wildcard(i-1,j-1,s,t,dp);
        }
        else if(t[j] == '*'){
            return dp[i][j] = wildcard(i-1,j,s,t,dp) || wildcard(i,j-1,s,t,dp);
        }
        else{
            return dp[i][j] = false;
        }
    }
    bool isMatch(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return wildcard(n-1,m-1,s,t,dp);
    }
};