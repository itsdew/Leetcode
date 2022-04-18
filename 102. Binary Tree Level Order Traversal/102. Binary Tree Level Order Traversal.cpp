//Devendra Uraon 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<TreeNode *> list;
        
        if (root != NULL)
            list.push_back(root);
        
        vector<vector<int>> res;        
        while (list.size() > 0)
        {
            vector<TreeNode *> op = list;
            
            list.clear();
            vector<int> v;
            for (TreeNode* &node : op)
            {
                v.push_back(node->val);
                
                if (node->left != NULL)
                    list.push_back(node->left);
                if (node->right != NULL)
                    list.push_back(node->right);
            }
            
            res.push_back(v);
        }
        
        return res;
    }
};
