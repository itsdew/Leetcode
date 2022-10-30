//Author: Devendra Uraon
class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int, int>> vec;
        int n = plantTime.size();
        for (int i = 0; i < n; i++) {
            vec.push_back({plantTime[i], growTime[i]});
        }
        
        sort(begin(vec), end(vec), [](auto &p1, auto &p2){
            return p1.second == p2.second ? p1.first < p2.first : p1.second > p2.second;
        });
        int farthest;
        int prev = 0;
        for (int i = 0; i < n; i++) {
            prev += vec[i].first;
            farthest = max(farthest, prev + vec[i].second);
        }
        return farthest;
    }
};