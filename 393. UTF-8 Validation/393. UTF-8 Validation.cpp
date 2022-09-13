//Author: Devendra Uraon 
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int m[6] = {128, 192, 224, 240, 248, 10000000};
        int nbits,remaningbits = 0;
        for(auto d: data){
            nbits = 0;
            while(d >= m[nbits]) nbits++;
            if (nbits >= 5) return false;
            if (remaningbits>0){
                if (nbits!=1) return false;
                remaningbits--;
            }
            else if (nbits >= 2) remaningbits = nbits-1;
            else if (nbits == 1) return false;
        }
        return remaningbits == 0;
    }
};
