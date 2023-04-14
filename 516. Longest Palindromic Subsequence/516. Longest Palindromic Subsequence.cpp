//Author: Devendra Uraon 
class Solution {
public:    
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        vector<int> pre(s.size()+1, 0), cur(s.size()+1, 0);
        for(int i = 1; i <= s.size(); i++){
            for(int j = 1; j <= s.size(); j++){
                if(s[i-1] == s2[j-1]) cur[j] = 1 + pre[j-1];
                else cur[j] = max(pre[j], cur[j-1]);
            }
            pre = cur;
        }
        return pre[s.size()];
    }
};


