//Author: Devendra Uraon
class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        
        string s = "1";
        for(int i=2; i<=n; i++){
            string t = "";
            s = s + '/';
            int count = 1;
            for(int j=1; j<s.length(); j++){
                if(s[j] != s[j-1]){
                    t = t + to_string(count);
                    t = t + s[j-1];
                    count = 1;
                }
                else
                    count ++;
            }
            s = t;
        }
        return s;
    }
};