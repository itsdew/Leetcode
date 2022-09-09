//Author: Devendra Uraon
class Solution {
public:
    static bool cmp(vector<int>& v1,vector<int>& v2){
        return v1[0] == v2[0] ? v1[1]>v2[1] : v1[0]<v2[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& nums){
        int n = nums.size(), count = 0;
        sort(nums.begin(), nums.end(), cmp);
        stack<int> s;
        for(int i = 0; i < n; i++){
            while(s.size() && s.top()<nums[i][1]){
                s.pop();
                count++;
            }
            s.push(nums[i][1]);
        }
        return count;
    }
};