//Devendra Uraon 
class Solution {
private:
    vector<TreeNode *> num;
    void treeToVector(TreeNode *root) {
        if (!root) return;
        treeToVector(root->left);
        num.push_back(root);
        treeToVector(root->right);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        treeToVector(root);
        if (num.size() <= 1) return root;
        for (int i = num.size()-2; i >= 0; i--) { num[i]->val += num[i+1]->val; }
        return root;
    }
};
