//Devendra Uraon
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;
        sum -= root->val;
        return sum == 0 && root->left == NULL && root->right == NULL ? true : hasPathSum(root->left, sum) | hasPathSum(root->right, sum);
    }
};