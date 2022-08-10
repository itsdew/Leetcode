//Author: Devendra Uraon 
class Solution {
public:
    
    TreeNode *Make(int b, int e, vector<int> &N)
    {
        int mid=(e+b)/2;
        
        TreeNode *R=new TreeNode(N[mid]);
        
        if(mid>b) R->left= Make(b,mid-1,N);
        if(mid<e) R->right=Make(mid+1,e,N);
        
        return(R);
    }
    
    
    TreeNode* sortedArrayToBST(vector<int>& N) {
        
        int n=N.size();
        return(Make(0,n-1,N));
    }
};
