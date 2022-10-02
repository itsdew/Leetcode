//Author: Devendra Uraon
#define ll long long
class Solution {
public:
    ll mod = 1e9+7; 
    ll ans = 0; 
   int cal(int n, int k, int tar, vector<vector<int>>& dp ){
        if(tar<0) return 0;
        if(n == 0){
            if(tar == 0) return 1;
            return 0; 
        }
       if(dp[n][tar] != -1) return dp[n][tar]; 
       ll ans = 0;
       for(int i = 1 ; i <= k; i++){
          ans += cal(n-1 ,  k , tar-i ,dp ) % mod;
       }
        return dp[n][tar] = ans % mod;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1 , vector<int>(target+1 , -1 )); 
    return cal(n , k, target, dp ) ; 
        
    }
};