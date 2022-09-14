//Author: Devendra Uraon 
class Solution {
public:
    void solve(TreeNode* root, vector<int> v,int &count){
        if (!root->left && !root->right){ // at a leaf node 
            v[root->val-1] = v[root->val -1] +1;
            int odd = 0;
            for(int i:v){
                if (i%2 == 1) odd++;
            }
            if (odd <=1 ) count++;
            return;
        }
        v[root -> val-1] = v[root -> val -1] +1;
        if (root -> left) solve(root -> left, v,count);
        if (root -> right) solve(root -> right, v,count);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> v(9, 0);
        int count = 0;
        solve(root, v,count);
        return count;
    }
};
