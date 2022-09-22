//Author: Devendra Uraon
class Solution {
public:
    string reverseWords(string s) {
        string ans, sol;
        s.push_back(' ');
        for(int i = 0; i < s.size(); i++){
            if(s[i] != ' '){
                ans.push_back(s[i]);
            }
            else{
                ans.push_back(' ');
                reverse(ans.begin(), ans.end());
                sol += ans;
                ans = "";
            }
            
        }
        reverse(sol.begin(), sol.end());
        sol.pop_back();
        reverse(sol.begin(), sol.end());
        return sol;
    }
};