//Devendra Uraon 
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        
        stack<TreeNode*> left, right;
        left.push(root);
        while(!left.empty() || !right.empty()) {
            vector<int> level;
            if (!left.empty()) {
                // left is NOT empty, pop left push right
                while(!left.empty()) {
                    TreeNode *node = left.top(); left.pop();
                    level.push_back(node->val);
                    if (node->left)
                        right.push(node->left);
                    if (node->right)
                        right.push(node->right);
                }
            } else {
                // Right is NOT empty, pop right push left
                while(!right.empty()) {
                    TreeNode *node = right.top(); right.pop();
                    level.push_back(node->val);
                    if (node->right)
                        left.push(node->right);
                    if (node->left)
                        left.push(node->left);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};
