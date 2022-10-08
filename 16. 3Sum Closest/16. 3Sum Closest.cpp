//Author: Devendra Uraon 
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), sum = nums[0] + nums[1] + nums[2];
        int closest = abs(target - sum);
        for(int first = 0; first < n-2; first++){
            int second = first + 1, third = n -1;
            while(second < third){
                int sum2 = nums[first] + nums[second]+ nums[third];
                int checking = abs(target - sum2);
                if(closest > checking){
                    sum = sum2;
                    closest = checking;
                }
                if(sum2 > target) third--;
                else second++;
            }
        }
        return sum;
    }
};
