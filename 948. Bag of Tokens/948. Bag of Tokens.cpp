//Author: Devendra Uraon 
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int c = 0;
        sort(tokens.begin(),tokens.end());
        int l = 0, r = tokens.size()-1;
        int ans = 0;
        while(l <= r){
            if(power >= tokens[l]){
                c++;
                ans = max(ans,c);
                power -= tokens[l];
                l++;
            }
            else if(power < tokens[l] && c>=1){
                power += tokens[r];
                c--; r--;
            }
            else if(c==0)
                break;
        }
        return ans;
    }
};
