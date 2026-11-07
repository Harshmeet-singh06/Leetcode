class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        int profit = 0;
        int mine = INT_MAX;
        for(int i=0;i<n;i++){
            mine = min(mine,a[i]);
            profit = max(profit,a[i] - mine);
        }
        return profit;
    }
};