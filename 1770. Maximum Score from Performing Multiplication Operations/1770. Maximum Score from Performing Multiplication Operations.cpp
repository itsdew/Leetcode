//Author: Devendra Uraon 
class Solution {
public:
    int solve(vector<int>& nums, vector<int>& multipliers,int s,int e,int i,vector<vector<int>>&dp){
    if(i == multipliers.size()) return 0;
    if(dp[i][s] != INT_MIN) return dp[i][s];
    
    int left = multipliers[i] * nums[s] + solve(nums, multipliers, s+1, e, i+1, dp);
    int right = multipliers[i] * nums[e] + solve(nums, multipliers, s, e-1, i+1, dp);
    
    return dp[i][s] = max(left, right);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
    int n = nums.size() , m = multipliers.size();
    vector<vector<int>>dp(1001, vector<int>(1001, INT_MIN));
    return solve(nums, multipliers, 0, n-1, 0, dp);
    }
};
