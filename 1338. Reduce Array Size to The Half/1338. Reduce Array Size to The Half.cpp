//Author: Devendra Uraon
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        map<int,int>mp;
        for(auto i:arr){
            mp[i]++;
        }
        
        vector<pair<int,int>>use;
        for(auto i:mp){
            use.push_back({i.second,i.first});
        }
        sort(use.begin(),use.end(),greater<pair<int,int>>());
        int n=arr.size();
        
        int sum=0,count=0;
        for(int i=0;i<use.size();i++){
            if(2*sum<n){
                sum+=use[i].first;
                count++;
            }
            
        }
       return count;
    }
};