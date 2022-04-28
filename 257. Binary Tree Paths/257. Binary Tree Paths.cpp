//Devendra Uraon
class Solution {
public:
    vector<string> ans;
    void fun(TreeNode* root,string s)
    {
        if(!root->left && !root->right)
            ans.push_back(s);
        if(root->left)
            fun(root->left,s+"->"+to_string(root->left->val));
        if(root->right)
            fun(root->right,s+"->"+to_string(root->right->val));
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        string s="";
        s+=to_string(root->val);
        fun(root,s);
        return ans;
    }
};
