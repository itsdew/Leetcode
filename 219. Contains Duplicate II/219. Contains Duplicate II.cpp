//Author: Devendra Uraon 
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        size_t size = nums.size();
        int i;
        unordered_map<int,int> m;
        for (i = 0; i < size; ++i) {
            if (m.find(nums[i]) == m.end()) m[nums[i]] = i;
            else if (i-m[nums[i]] <= k) return true; 
            else m[nums[i]] = i;
        }
        return false;
    }
};
