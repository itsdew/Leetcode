//Author: Devendra Uraon 
class Solution {
public:
    int numDecodings(string s){
        vector<int> hg(s.size()+1, 0);
        int ans = 0;
        ans = helper(s, 0, hg);
        return ans;
    }
    int helper(string s, int i, vector<int>&hs) {
        if(s.size() == i) return 1;
        if(s[i] == '0') return 0;
        if(hs[i] > 0) return hs[i];
        if(i == s.size()-1) return 1;
        if(i < s.size()-1){
            int num = (s[i] - '0') * 10 + (s[i+1] - '0');
            if(num>0 && num<=26){
                return hs[i] = helper(s, i+1, hs) + helper(s, i+2, hs);
            }
        }
        return hs[i]=helper(s, i+1, hs);
    }
};
