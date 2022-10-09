//Author: Devendra Uraon
class Solution {
public:
    vector<int> v;
    void inorder(TreeNode* root){
        if(!root) return ;
        inorder(root -> left);
        v.push_back(root -> val);
        inorder(root -> right);
    }
    bool findTarget(TreeNode* root, int k){
        if(!root) return false;
        inorder(root);
        int l = 0, r = v.size()-1;
        while(l < r){
            if(v[l]+v[r] == k) return true;
            else if(v[l]+v[r]<k) l++;
            else r--;
        }
        return false;
    }
};
