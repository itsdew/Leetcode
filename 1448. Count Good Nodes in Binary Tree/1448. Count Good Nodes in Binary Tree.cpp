//Author: Devendra Uraon 
class Solution {
    int sum = 0;
    void doRec(TreeNode* root, int currentMax) {
        if(root) {
            if(root->val >= currentMax || currentMax == INT_MIN) sum++;
            doRec(root->left, max(currentMax, root->val));
            doRec(root->right, max(currentMax, root->val));
        }
    }
public:
    int goodNodes(TreeNode* root) {
        doRec(root, INT_MIN);
        return sum;
    }
};
