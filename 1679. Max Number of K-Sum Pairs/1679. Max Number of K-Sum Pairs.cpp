//Devendra Uraon
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans=0;
        unordered_map<int,int> mp;
        mp[nums[0]]++;
        for(int i=1;i<nums.size();i++){
            if(mp.find(k-nums[i])!=mp.end() and mp[k-nums[i]]>0){
                mp[k-nums[i]]--; // Decreasing the count of other number in the map
                ans++;
            }
            else mp[nums[i]]++;
        }
        return ans;
    }
};