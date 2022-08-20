//Author: Devendra Uraon
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        vector<long> dp(stations.size() + 1, startFuel);
        for(int i = 0; i < stations.size(); i++) {
            for(int t = i; t >= 0; t--) {
                if(dp[t] < stations[i][0]) break;
                dp[t + 1] = max(dp[t + 1], stations[i][1] + dp[t]);
            }
        }
        for(int i = 0; i <= stations.size(); i++){
            if(dp[i]>=target)return i;
        }
        return -1;
    }
};