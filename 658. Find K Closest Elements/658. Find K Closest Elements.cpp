//Author: Devendra Uraon 
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>, vector<pair<int,int>>> pq;
        for(auto n: arr){
            pq.push({abs(n - x), n});
            if(pq.size() > k) pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()) ans.push_back(pq.top().second), pq.pop();
        sort(ans.begin(), ans.end());
        return ans;
    }
};
