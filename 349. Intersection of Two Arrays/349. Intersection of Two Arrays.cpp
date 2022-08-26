//Author: Devendra Uraon 
class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {

     unordered_set<int> s;
        for(int i=0; i<a.size(); i++)
           s.insert(a[i]);
        
      vector<int> res;
        
        for(int j=0; j<b.size(); j++)
        {
            if(s.find(b[j])!=s.end())
            {
                res.push_back(b[j]);
                s.erase(b[j]);
            }
        }
        return res;
    }
    
};
