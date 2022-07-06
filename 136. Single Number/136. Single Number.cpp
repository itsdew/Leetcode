//Devendra Uraon 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sol = 0, T = nums.size(), i = 0;
        while(T--){
            sol = nums[i]^sol;
            ++i;
        }
        return sol;
    }
};
