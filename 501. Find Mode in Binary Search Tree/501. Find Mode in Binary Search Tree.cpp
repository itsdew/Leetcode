//Devendra Uraon
class Solution {
    vector<int> result;
    int maxreps = 0;
    void solve(TreeNode* cur, int & curval, int & reps) 
    {
        if (cur == nullptr)
            return;
        solve(cur->left, curval, reps);
        if (cur->val == curval)
            reps ++;
        else{
            if (reps > maxreps)
            {
                result.clear();
                result.push_back(curval);
                maxreps = reps;
            }else if (reps > 0 && reps == maxreps)
                result.push_back(curval);
            curval = cur->val, reps = 1;
        }
        solve(cur->right, curval, reps);
    }
public:
    vector<int> findMode(TreeNode* root) {
        int curval = 0, reps = 0;
        solve(root, curval, reps);
        if (reps > maxreps)
        {
            result.clear();
            result.push_back(curval);
            maxreps = reps;
        }else if (reps > 0 && reps == maxreps)
            result.push_back(curval);
        return result;
    }
};