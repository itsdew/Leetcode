//Author: Devendra Uraon 
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) return NULL;
        root->left = pruneTree(root -> left);
        root->right = pruneTree(root -> right);
        if(root->val == 0 &&   !root -> left && !root -> right) return NULL;
        return root;
    }
};
