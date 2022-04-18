//Devendra Uraon 
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> map;
        for (int i = 0; i < inorder.size(); ++i)
        {
            map[inorder[i]] = i;
        }
        
        return helper(0, postorder.size() - 1, 0, inorder.size() - 1, postorder, map);
    }
    
    TreeNode* helper(int poStart, int poEnd, int inStart, int inEnd, vector<int>& postorder, unordered_map<int, int>& map)
    {
        if (poStart > poEnd || inStart > inEnd)
        {
            return NULL;
        }
        
        int mid = postorder[poEnd];
        TreeNode* root = new TreeNode(mid);
        int inIndex = map[mid];
        
        root->left = helper(poStart, poStart + inIndex - inStart - 1, inStart, inIndex - 1, postorder, map);
        root->right = helper(poStart + inIndex - inStart, poEnd - 1, inIndex + 1, inEnd, postorder, map);
        
        return root;
    }
    
};
