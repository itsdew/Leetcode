//Author: Devendra Uraon
class Solution {
public:
    string intToRoman(int num) {
        int n[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        int i = 0;
        string ans;
        while (num != 0){
            while (n[i] > num) ++i;
            num = num - n[i];
            ans += roman[i];
        }
        return ans;
    }
};