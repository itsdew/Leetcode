//Author: Devendra Uraon
class Solution {
public:
void helper(TreeNode* root, map<int, multiset<pair<int, int>>> &mp, int row, int col){
        if(root==NULL){
            return;
        }
        mp[col].insert({row, root->val});
        helper(root->right, mp, row+1, col+1);
        helper(root->left, mp, row+1, col-1);
        return;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, multiset<pair<int, int>>> mp;
        helper(root, mp, 0, 0);
        vector<vector<int>> ans;
        for(auto it:mp){
            vector<int> temp;
            for(auto itr:it.second){
                temp.push_back(itr.second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};