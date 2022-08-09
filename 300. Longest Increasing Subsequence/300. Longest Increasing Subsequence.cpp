//Author: Devendra Uraon
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        set<int> s;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            auto it = s.lower_bound(nums[i]);
            if(it == s.end()) {
                s.insert(nums[i]);
                continue;
            }
            s.erase(it);
            s.insert(nums[i]);
        }
        return (int)s.size();
    }
};