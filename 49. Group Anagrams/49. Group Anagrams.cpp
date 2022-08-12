//Author: Devendra Uraon 
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> m;
        for(auto it:strs){
            string temp = it;
            sort(temp.begin(), temp.end());
            m[temp].push_back(it);
        }
        
        vector<vector<string>> ans;
        for(auto [temp,vec]:m)
            ans.push_back(vec);
        
        return ans;
    }
};
