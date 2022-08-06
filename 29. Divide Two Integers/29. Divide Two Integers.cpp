//Author: Devendra Uraon 
class Solution {
public:
    int divide(int dividend, int divisor) {
        //bitwise
        long long n = dividend;
        long long m = divisor;
        int res = n<0 ^ m<0 ? -1 : 1;
        n = abs(n);
        m = abs(m);
        long long q=0, t=0;
        for(long long i = 31; i>=0; i--){ 
            if(t + (m<<i) <= n ){
                t += m<<i;
                q = q | (1ll<<i);
            }
        }
        if(res < 0) q = -q;
        if(q < INT_MIN) return INT_MIN;
        if(q >= INT_MAX) return INT_MAX;
        return q;
    }
};
