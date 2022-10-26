//Author: Devendra Uraon
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1) return false;
        unordered_map<int, int> m;
        int sum = nums[0];
        m[sum%k] = 0;
        for(int i = 1; i < n; i++){
            sum += nums[i];
            if(sum%k == 0) return true;
            if(m.find(sum%k) != m.end() && i - m[sum%k] >= 2) return true;
            if( (nums[i-1] + nums[i]) %k == 0) return true; 
            m[sum%k] = i;
        }
        return false;
    }
};