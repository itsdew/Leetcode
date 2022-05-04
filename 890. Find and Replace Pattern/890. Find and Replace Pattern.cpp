//Devendra Uraon
class Solution {
public:
    bool compare(string a, string b){
        if(a.size() != b.size()) return false;
        for(int i =0 ; i < a.size(); ++i){
            for(int j = 0; j <= a.size(); ++j){
                if(b[i] == b[j] && a[i] != a[j]){
                    return false;
                } else if(b[i] != b[j] && a[i] == a[j]){
                    return false;
                }
            }
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> v;
        for(int i = 0; i < words.size(); ++i){
            if(compare(words[i], pattern) == true){
                v.push_back(words[i]);
            }
        }
        return v;
    }
};