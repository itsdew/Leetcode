//Author: Devendra Uraon 
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>>mp;
        
        for(int i = 0; i < paths.size(); i++){
            
            string directory=paths[i];
            string s, directoryName;
            
            bool firstWord = true;
            stringstream ss(directory);
            
            while(getline(ss, s, ' ')){
                
                if(firstWord){
                    directoryName = s;
                    firstWord = false;
                }
                else{
                    int j = 0;
                    int fileLength = 0;
                    while(j < s.size() and s[j++]!='(') fileLength++;
                    string fileName = s.substr(0, fileLength);
                    
                    j = fileLength+1;
                    
                    int contentLength = 0;
                    while(j < s.size() && s[j++] != ')') contentLength++;
                    string content = s.substr(fileLength+1, contentLength);
                    
                    mp[content].push_back(directoryName + "/" + fileName);
                }
            }
        }
        vector<vector<string>>ans;
        
        for(auto &[content, directory]:mp){
            if(directory.size() == 1) continue;
            ans.push_back(directory);
        }
        
        return ans;
    }
};
