//Author: Devendra Uraon
class Solution {
public:
    string simplifyPath(string path) {
        string token = "";

        stringstream ss(path);

        stack<string> stk;

        while(getline(ss, token, '/')){
            if(token == "" || token == ".") continue;

            if(token != "..") stk.push(token);
            else if(!stk.empty()) stk.pop();
        }

        if(stk.empty())
            return "/";

        string res = "";

        while(!stk.empty()){
            res = "/" + stk.top() + res;
            stk.pop();
        }
        return res;
    }
};