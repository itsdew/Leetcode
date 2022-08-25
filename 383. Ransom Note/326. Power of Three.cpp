//Author: Devendra Uraon 
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
    bool a = 0;
	int alphabet[26]={0};
    int alphabet1[26]={0};
	for(int i = 0; i < ransomNote.size(); i++){
		alphabet[ransomNote[i]-'a']++;
	}
        for(int i = 0; i < magazine.size(); i++){
		alphabet1[magazine[i]-'a']++;
	}
        for(int i = 0; i < ransomNote.size(); i++){
            if(alphabet[ransomNote[i]-'a'] <= alphabet1[ransomNote[i]-'a']){
                a = 1;
            }
            else{
                a = 0;
                break;
            }
    }
        return a;
    }
};
