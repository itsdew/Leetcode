//Author: Devendra Uraon 
class Solution {
public:
    int mod = 1e9 + 7;
    int countVowelPermutation(int n) {
        int p = 0; 
        vector<vector<long long int>>dp(n ,vector<long long int>(5 , 0));
        dp[0][0] = 1; dp[0][1] = 2; dp[0][2] = 4; dp[0][3] = 2; dp[0][4] = 1;
        if(n == 1) return 5 ;
        if(n > 2){
            for(int i = 1; i <= n-2; i++){
                for(int  j = 0; j < 5;j++){
                    if(j == 0) dp[i][j] +=(dp[i-1][1])%mod;
                    if(j == 1) dp[i][j] +=(dp[i-1][0] + dp[i-1][2])%mod;
                    if(j == 2) dp[i][j] +=(dp[i-1][0] + dp[i-1][1] + dp[i-1][3] + dp[i-1][4])%mod;
                    if(j == 3) dp[i][j] +=(dp[i-1][2] + dp[i-1][4])%mod;
                    if(j == 4) dp[i][j] +=(dp[i-1][0])%mod;
                }
                p = i;
            }
        }
        long long int ans = 0 ;
        for(int j = 0; j < 5; j++)
         ans += dp[p][j]%mod;
        return ans% mod; 
    }
};
