//Devendra Uraon 
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
    
private:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int prel, int prer, int inl, int inr) {
        if (prel > prer) return NULL;
        TreeNode* root = new TreeNode(preorder[prel]);
        int pos;
        for (pos=inl; pos<=inr; pos++)
            if (root->val == inorder[pos])
                break;
        root->left = buildTree(preorder, inorder, prel+1, prel+pos-inl, inl, pos-1);
        root->right = buildTree(preorder, inorder, prel+pos-inl+1, prer, pos+1, inr);
        return root;
    }
};
