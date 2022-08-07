//Author: Devendra Uraon 
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> solve;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            solve.push_back(sum);
        }
        return solve;
    }
};
