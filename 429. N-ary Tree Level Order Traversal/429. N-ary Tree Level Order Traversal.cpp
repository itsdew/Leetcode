//Author: Devendra Uraon 
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<vector<Node*>> q;
        vector<int> temp;
        
        if(!root) return ans;
        
        temp.push_back(root -> val);
        q.push(root -> children);
        ans.push_back(temp);
 
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            while(size--){
                auto cur = q.front();
                q.pop();
                
                for(auto it:cur){
                    q.push(it -> children);
                    temp.push_back(it -> val);
                }
            }
            if(temp.size() > 0)
                ans.push_back(temp);
        }
        return ans;
    }
};
