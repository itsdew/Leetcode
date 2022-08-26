//Author: Devendra Uraon
class Solution {
public:
    unordered_set<string>mp;
    Solution(){
       
        int n=1;
        while(n<=1000000000){
            string s=to_string(n);
            sort(s.begin(),s.end());
            mp.insert(s);
            n<<=1;
        }
    }
    bool reorderedPowerOf2(int n) {
        string v=to_string(n);
        sort(v.begin(),v.end());
        return mp.count(v);
    }
};