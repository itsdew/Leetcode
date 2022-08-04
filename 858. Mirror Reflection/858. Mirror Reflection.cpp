//Author: Devendra Uraon
class Solution {
public:
    int mirrorReflection(int p, int q) {
        while((p%2==0) && (q%2==0)){                //executing till getting odd either p or q
            p/=2; q/=2;
        }
        if((p%2) == 0 && (q%2)!=0) return 2;         //p = even, q = odd
        if((p%2) != 0 && (q%2)!=0) return 1;         //p = odd, q = odd
        return 0;                                    //p = odd, q = even
    }
};