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
        // int n = s.size();
        // int m = t.size();
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return wildcard(n-1,m-1,s,t,dp);
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        dp[0][0] = true;
        for(int i=1;i<=n;i++){
            dp[i][0] = false;
        }
        for(int j = 1; j <= m; j++){
            if(t[j-1] == '*'){
                dp[0][j] = dp[0][j-1];
            }
            else{
                dp[0][j] = false;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1] || t[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(t[j-1] == '*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else{
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
};