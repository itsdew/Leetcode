//Author: Devendra Uraon
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1[0] == '0' || num2[0] == '0') return "0";
        vector<int> v(num1.size()+num2.size(),0);
        for(int i = num2.size()-1; i >= 0; i--){
            for(int j = num1.size()-1; j >= 0; j--){
                v[i+j+1] += (num2[i]-'0')*(num1[j]-'0');
                v[i+j] += v[i+j+1]/10;
                v[i+j+1] %= 10;
            }
        }
        string str;
        int c = 0;
        for(int i = 0; i<v.size(); i++){
            if(v[i] == 0 && c == 0) continue;
            str += to_string(v[i]);
            c=1;
        }    
        return str;
    }
};