//Devendra Uraon
class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        std::vector<int> results;
        int max = 0;
        
        ConvertTree(root);
        
        for(std::pair<int, int> pr : mp) {
            if(max < pr.second)
                max = pr.second;
        }
        
        for(std::pair<int, int> pr : mp) {
            if(pr.second == max)
                results.push_back(pr.first);
        }
        
        return results;
    }
private:
    int ConvertTree(TreeNode* root) {
        if(!root)
          return 0;
        int l = ConvertTree(root->left), r = ConvertTree(root->right);
        root->val = root->val + l + r;
        mp[root->val]++;
        return root->val;
    }
    
    std::unordered_map<int, int> mp;
};