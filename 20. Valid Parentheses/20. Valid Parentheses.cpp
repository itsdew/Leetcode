//Author: Devendra Uraon
class Solution {
public:
    int match(char a,char b){
        if(a=='('&&b==')'){
            return 1;
        }
        else if(a=='['&& b==']'){
            return 1;
        }
        else if(a=='{'&&b=='}'){
            return 1;
        }
        return 0;
    }
    bool isValid(string s) {
        if(s.size()==1){
            return false;
        }
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='['||s[i]=='{'){
                st.push(s[i]);
            }
            else if(s[i]==')'|| s[i]==']'|| s[i]=='}'){
                if(!st.empty() && match(st.top(),s[i])){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(!st.empty()){
            return false;
        }
        return true;
    }
};
