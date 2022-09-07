//Author: Devendra Uraon 
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        ans_fun(0, temp, ans, candidates, target, 0);
        return ans;
    }
    
    void ans_fun(int sums, vector<int>&temp, vector<vector<int>>&ans, vector<int> &cand, int targ, int pos){
        if(sums == targ){
            ans.push_back(temp);
        }
        if(sums < targ && pos < cand.size()){
            temp.push_back(cand[pos]);
            ans_fun(sums + cand[pos], temp, ans, cand, targ, pos);
            temp.pop_back();
            ans_fun(sums, temp, ans, cand, targ, pos+1);
        }
    }
};
