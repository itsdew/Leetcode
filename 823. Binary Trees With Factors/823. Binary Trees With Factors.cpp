//Author: Devendra Uraon 
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        sort(A.begin(), A.end());
        const long Mod = 1e9+7;        
        unordered_map<int, long> dp;
        for(int i = 0; i < A.size(); i++){
            dp[A[i]] = 1;
            for(int j = 0; j < i; j++){ // A[i] = A[j] *  A[i]/A[j]
                if(A[i] % A[j] ==0 && dp.count(A[i] / A[j])){
                    dp[A[i]] += (dp[A[j]] * dp[A[i] / A[j]]) % Mod; 
                }
            }
        }
        long ans = 0;
        for(auto& i: dp)
            ans = (ans + i.second) % Mod;
        return ans % Mod;
    }
};
