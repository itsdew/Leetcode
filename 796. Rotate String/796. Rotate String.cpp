//Author: Devendra Uraon
class Solution {
public:
    bool rotateString(string s, string goal) {
    queue<char> q;
    int n=s.size();

    for(char c:goal)
       q.push(c);
    
    while(n--){
       if(q.front() == s[0]){
           queue<char> tq = q;
           string str;
           
           while(tq.size()){
                str += tq.front();
                tq.pop();
           }
           if(str == s) return true;
       }
        char y=q.front();
        q.push(y);
        q.pop();
    }
    return false; 
    }
};