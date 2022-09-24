//Author: Devendra Uraon 
class Solution {  
    vector<vector<int>> ans;
    vector<int> path;
    int sum = 0, target;
    
    void dfs(TreeNode* x) {
        if (!x) return;
        sum += x->val;
        path.push_back(x -> val);
        if (sum == target && !x -> left && !x -> right)
            ans.push_back(path);
        dfs(x -> left);
        dfs(x -> right);
        sum -= x -> val;
        path.pop_back();
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        dfs(root);
        return ans;
    }
};
