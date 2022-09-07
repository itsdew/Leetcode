//Author: Devendra Uraon 
class Solution {
private:
    void bi(TreeNode*root, string &s){
        if(root==NULL)
            return;
        s += "(";
        s += to_string(root->val);
         if(root -> left) bi(root -> left, s);
        else 
            if(root -> right) 
                s += "()"; 
        bi(root->right, s);
        s += ")";
        return;
    }
public:
    string tree2str(TreeNode* root) {
        string s;
        bi(root, s);
        return s.substr(1, s.size()-2);
    }
};
