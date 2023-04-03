//Author: Devendra Uraon
class Solution {
public:
    bool isPossible(vector<int>& people, int no_boats, int& limit) {
        int left = 0, right = people.size() - 1;
        while(left < right and no_boats) {
            if(people[left] + people[right] <= limit) {
                left++, right--;
            }
            else right--;
            no_boats--;
        }
        if(left == right) return no_boats;   //no boats
        return left > right;
    }
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int minval = 1, maxval= people.size(), medval;
        while(minval <= maxval) {
            medval = minval + ((maxval - minval)>>1);
            if(isPossible(people, medval, limit)) maxval = medval - 1;
            else minval = medval + 1;
        }
        return minval;
    }
};