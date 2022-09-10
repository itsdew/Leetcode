//Author: Devendra Uraon
class Solution {
public:
   int fun(vector<int>& prices,bool buy, int k, int day, vector<vector<vector<int>>> &dp){
        if(day >= prices.size()) return 0;
        if(k <= 0) return 0;
        if(dp[day][k][buy] != -1) return dp[day][k][buy];
        int a = 0, b = 0;
        if(buy) a = fun(prices, false, k, day+1, dp) - prices[day];
        else a = fun(prices, true, k-1, day+1, dp) + prices[day];
         b = fun(prices, buy, k, day+1, dp);
        return dp[day][k][buy] = max(a, b);
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>> (k+1, vector<int> (2,-1)));
        return fun(prices, true, k, 0, dp);
    }
};