//Author: Devendra Uraon 
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& n, vector<vector<int>>& q) {
        int sum = 0, val, index;
        vector<int> vec;
        for(int i = 0; i < n.size(); i++) if(n[i]%2 == 0) sum += n[i];
        for(int i = 0; i < q.size(); i++){
            val = q[i][0];
            index = q[i][1];
            if(n[index]%2 == 0) sum -= n[index];
            n[index] += val;
            if(n[index]%2 == 0) sum += n[index];
            vec.push_back(sum);
        } 
        return vec;
    }
};
