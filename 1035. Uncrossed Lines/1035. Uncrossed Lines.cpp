//Devendra Uraon
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> um;
        int n = nums1.size();
        int m = nums2.size();
        
        int dp[2][m+1];
        dp[0][0] = 0;
        dp[1][0] = 0;
        for(int j=1;j<=m;++j){
            dp[0][j] = 0;
            if(nums1[0] == nums2[j-1]) dp[0][j] = 1;
            dp[0][j] = max(dp[0][j],dp[0][j-1]);
        }
        for(int i=1;i<n;++i){
            int cr = i%2;
            int pv = (i+1)%2;
            for(int j=1;j<=m;++j){
                dp[cr][j] = max(dp[pv][j],dp[cr][j-1]);
                if(nums1[i] == nums2[j-1]) dp[cr][j] = max(dp[cr][j],dp[pv][j-1]+1);
            }
        }
        return dp[(n-1)%2][m];
    }
};