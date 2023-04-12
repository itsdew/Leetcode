//Author: Devendra Uraon
class Solution {
public:
    string removeStars(string s) {
        reverse(s.begin(),s.end());
        string ans;
        int ct = 0, n = s.size();
        for(int i = 0;i<n;i++){
            if(s[i] == '*'){
                ct--; continue;
            }
            if(ct < 0) ct++;
            else ans.push_back(s[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};