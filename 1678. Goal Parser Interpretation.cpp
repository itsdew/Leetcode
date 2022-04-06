class Solution {
public:
    string interpret(string command) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        string ans;
        for( int i = 0 ; i <= command.size()-1 ; i++){
            if(command[i] == 'G'){
                ans += 'G';
            } 
            if(command[i] == '('){
                if(command[i+1] == ')')
                    ans += 'o';
                else
                    ans += "al";
                    }
        }
        return ans;
    }
};
