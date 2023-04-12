//Author: Devendra Uraon 
class Solution {
public:
    vector<int> successfulPairs(vector<int>& v1, vector<int>& v2, long long success) {
        sort(v2.begin(), v2.end());
        int n = v1.size(), m = v2.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            long long req = (success + v1[i] - 1) / v1[i];
            if (req > v2[m - 1]) {
                ans.push_back(0);
                continue;
            }
            auto it = lower_bound(v2.begin(), v2.end(), req);
            ans.push_back(v2.end() - it);
        }
        return ans;
    }
};
