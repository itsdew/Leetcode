//Author: Devendra Uraon 
class Solution {
public:
    void solve(vector<string>&arr, vector<int>&taken, int pos, int &ans){
        if(pos == arr.size()){
            ans = max(ans, accumulate(taken.begin(), taken.end(), 0));
            return ;
        }
        
        solve(arr, taken, pos+1, ans);
        
        int i = 0;
        for(; i < arr[pos].size(); ++i){
            if(taken[arr[pos][i]-'a']) break;
            ++taken[arr[pos][i]-'a'];
        }
        
        if(i < arr[pos].size()){
           for(--i; i>=0; --i) --taken[arr[pos][i]-'a']; return;
        }
        
        solve(arr,taken,pos+1,ans);
        
        for(auto a : arr[pos])
            --taken[a-'a'];
    }
    int maxLength(vector<string>& arr) {
        int ans = 0;
        vector<int> taken(26, 0);
        solve(arr, taken, 0, ans);
        return ans;
    }
};
