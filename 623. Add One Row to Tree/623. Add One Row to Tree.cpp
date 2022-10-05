//Author: Devendra Uraon
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode *temp = new TreeNode (val);
            temp -> left = root;
            return temp;
        }
        insertNode(root, val, depth, 1);
        return root;  
    }
    
    void insertNode(TreeNode* root, int val, int depth, int current){
        if(root == NULL) return;
        if(current != depth-1){
            insertNode(root -> left, val, depth, current+1);
            insertNode(root -> right, val, depth, current+1);
        }    
        else{
            TreeNode *temp = root -> left;
            root -> left = new TreeNode (val);
            root -> left -> left = temp;
            temp = root -> right;
            root -> right = new TreeNode (val);
            root -> right -> right = temp;
        }
    }
};