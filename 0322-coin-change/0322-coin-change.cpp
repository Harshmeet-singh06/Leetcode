class Solution {
public:
    int coin(int i,vector<int>& a,int amount){
        if(amount == 0){
            return 0;
        }
        if(i == 0){
            if(amount % a[0] == 0){
                return amount/a[0];
            }
            else{
                return 1e8;
            }
        }
        int not_take = coin(i-1,a,amount);
        int take = 1e8;
        if(a[i] <= amount){
            take = 1 + coin(i,a,amount-a[i]);
        }
        return min(take,not_take);
    }
    int coinChange(vector<int>& a, int k) {
        // int n = a.size();
        // int ans = coin(n-1,a,amount);
        // if(ans >= 1e8){
        //     return -1;
        // }
        // return ans;
        int n = a.size();
        vector<vector<int>> dp(n, vector<int>(k+1, 1e8));

        for(int i = 0; i < n; i++){
            dp[i][0] = 0;
        }

        for(int i = 1; i <= k; i++){
            if(i % a[0] == 0){
                dp[0][i] = i / a[0];
            }
        }

        for(int i = 1; i < n; i++){
            for(int j = 0; j <= k; j++){
                int notpick = dp[i-1][j];
                int pick = 1e8;

                if(a[i] <= j){
                    pick = 1 + dp[i][j-a[i]];
                }

                dp[i][j] = min(pick, notpick);
            }
        }

        if(dp[n-1][k] >= 1e8) return -1;

        return dp[n-1][k];

    }
};