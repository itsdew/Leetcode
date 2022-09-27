//Author: Devendra Uraon 
class Solution {
public:
    
    bool dfs (vector <vector <int>>& v, int a, int b, vector <bool>& vis) {
        
        if (a == b) return true;
        vis [a] = true;
        
        for (int x : v [a]) {
            
            if (vis [x] == true) continue;
            if (dfs (v, x, b, vis)) return true;
        }
        
        return false;
    }
    
    bool equationsPossible(vector<string>& arr) {
        
        vector <vector <int>> v (26);
        for (int i = 0; i < arr.size (); i++) {
            
            string s = arr [i];
            
            if (s [1] == '=') {
                
                v [s [0] - 'a'].push_back (s [3] - 'a');
                v [s [3] - 'a'].push_back (s [0] - 'a');
            }
        }
        
        for (int i = 0; i < arr.size (); i++) {
            
            string s = arr [i];
            vector <bool> vis (26);
            
            if (s [1] == '!') {
                
                if (dfs (v, s [0] - 'a', s [3] - 'a', vis)) return false;
            }
        }
        
        return true;
    }
};
