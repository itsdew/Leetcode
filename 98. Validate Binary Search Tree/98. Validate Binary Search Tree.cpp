//Author: Devendra Uraon
class Solution {
public:
    
bool isBST(TreeNode *root, long long int min, long long int max){
	
	bool l=true,r=true;
	if(!root->left && !root->right){
		if(!(root->val >min && root->val < max))
			return false;
		else 
			return true;
	}
	if(!(root->val >min && root->val < max))
		return false;

	if(root->left)
		l = isBST(root->left, min, root->val);
	if(root->right)
		r = isBST(root->right, root->val, max);
		
	return l && r;
}

    bool isValidBST(TreeNode* root) {
	    long long int min = (long long int)INT_MIN-1, max = (long long int)INT_MAX+1;
	    return isBST(root,min,max);
    }
};
