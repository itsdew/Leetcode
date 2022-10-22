//Author: Devendra Uraon 
class Solution {
public:
    string minWindow(string s, string t) {
      int i=0;
      int j=0;
      int mini=INT_MAX;
      unordered_map<char,int>m;
        for(int i=0;i<t.size();i++){
            m[t[i]]++; 
        }
        
        int count =m.size();
        string ans="";
        while(j<s.size()){ 
                if(m.find(s[j])!=m.end()){
                m[s[j]]--;        
                if(m[s[j]]==0){
                    count--;
                }
            } 
            while(count==0){
                if(mini>j-i+1){
                    mini=min(mini,j-i+1);
                    ans=s.substr(i,j-i+1);
                }
                if(m.find(s[i])!=m.end()){
                    m[s[i]]++;
                    if(m[s[i]]==1){
                        count++;
                    }
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};
