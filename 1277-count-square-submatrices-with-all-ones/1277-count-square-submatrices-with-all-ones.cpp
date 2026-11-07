class Solution {
public:
    int countSquares(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            dp[0][i] = a[0][i];
        }
        for(int j=0;j<n;j++){
            dp[j][0] = a[j][0];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(a[i][j] == 0){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = 1 + min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
                }
            }
        }
        int sum = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum += dp[i][j];
            }
        }
        return sum;
    }
};