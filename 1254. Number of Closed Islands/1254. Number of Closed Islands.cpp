//Author: Devendra Uraon 
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = nums[0];
        long long sum = nums[0];
        for(int i = 1; i < n; i++){
            sum += nums[i];
            ans = max(ans, (sum + i) / (i + 1));
        }
        return ans;
    }
};
