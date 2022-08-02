//Author: Devendra Uraon 
class Solution {
public:    
    int uniquePaths(int m, int n) {
        double num = 1, div = 1;
        int max, min;
        
        if (m > n){
            max = m - 1;
            min = n - 1;
        }
        else{
            max = n - 1;
            min = m - 1;
        }
        
        for(int i = max + min; i > max; i--)
            num *= i;
        for (int i = 1; i <= min; i++)
            div *= i;

        return num / div;
    }
};
