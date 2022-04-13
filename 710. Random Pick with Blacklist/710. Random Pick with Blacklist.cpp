//Author: Devendra Uraon
class Solution {
    int last;
    unordered_map<int, int> remap;
public:
    Solution(int n, vector<int>& blacklist)
    {
        sort(blacklist.begin(), blacklist.end());
        last = n - 1;

        for(auto p = blacklist.rbegin(); p != blacklist.rend(); ++p, last--){
            if(*p != last){
                if(remap.count(last)){
                    remap[*p] = remap[last];
                }else{
                    remap[*p] = last;
                }
            }
        }
    }
    
    int pick()
    {
        const int m = rand() % (last + 1);
        return remap.count(m) ? remap[m] : m;
    }
};