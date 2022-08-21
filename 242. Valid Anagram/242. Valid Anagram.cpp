//Author: Devendra Uraon 
class Solution {
public:
    bool isAnagram(string s, string t) {
       int alphabet[26]={0};
	    for(int i = 0; i < s.size(); i++){
		    alphabet[s[i]-'a']++;
	    }
        int alphabet1[26]={0};
	    for(int i = 0; i < t.size(); i++){
		    alphabet1[t[i]-'a']++;
	    }
        bool flag = 1;
        for(int i = 0; i<26; i++){
	    if(alphabet[i] != alphabet1[i]){
	        flag = 0;
	        break;
	    }
	}
    return flag;
    }
};
