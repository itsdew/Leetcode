//Author: Devendra Uraon 
class Solution {
public:
    int maxPerformance(int n, std::vector<int> &speed, vector<int> &efficiency, int k){
        vector<pair<int, int>> vec;
        long sum = 0, result = 0; 
        for (int i = 0; i < n; i++) vec.push_back({efficiency[i], speed[i]});

        sort(vec.rbegin(), vec.rend());

        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) {
            if (i >= k) {
                sum -= pq.top();
                pq.pop();
            }
            sum += vec[i].second;
            pq.push(vec[i].second);
            result = max(result, sum * vec[i].first);
        }
        return result % static_cast<int>(1e9 + 7);
    }
};
