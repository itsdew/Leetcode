//Author: Devendra Uraon
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int i=1; i<=nums.size(); i++) mp[i] = 1;
        for(auto n : nums){
            mp[n]--;
            if(mp[n] < 0) ans.push_back(n);
        }
        for(auto m : mp){
            if(m.second == 1){
                ans.push_back(m.first);
                break;
            }
        }
        return ans;
    }
};