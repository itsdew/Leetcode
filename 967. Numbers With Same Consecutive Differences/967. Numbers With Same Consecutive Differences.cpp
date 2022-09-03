//Author: Devendra Uraon
class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>t;
        for(int i=1;i<=9;i++){
            if(i-k>=0){
                t.push_back(11*i-k);
            }
            if(i+k<=9 && k!=0){
                t.push_back(11*i+k);
            }
        }
        n = n-2;
        vector<int>tm;
        while(n--){
            for(int i:t){
                int m = i%10;
                if(m-k>=0){
                    tm.push_back(10*i+m-k);
                }
                if(m+k<=9 && k!=0){
                    tm.push_back(10*i+m+k);
                }
            }
            t = tm;
            tm.clear();
        }
        return t;
    }
};