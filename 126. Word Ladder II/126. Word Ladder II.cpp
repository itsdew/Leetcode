//Author: Devendra Uraon - TLE 
//Helper: Tania Rebello - TLE.Eliminator 
class Solution {
public:
    map<string,vector<string>> parent;
    queue<string> q;
    vector<string> path;
    vector<vector<string>> ans;
    unordered_map<string,int> distance;
    void location(string str,vector<string> &path){
         if(str=="0"){
              ans.push_back(path);
              return;
         }
         for(string node : parent[str]){
              path.push_back(str);
              location(node,path);
              path.pop_back();
         }
    }
    vector<vector<string>> findLadders(string first, string last, vector<string> &list){
         for(string node : list) distance[node] = INT_MAX , parent[node] = {};
         parent[first] = {"0"};
         distance[first] = 1;
         q.push(first);
         while(!q.empty()){
             string par = q.front();
             q.pop();
             if(par==last) break;
             for(int i=0; i<par.size(); i++){
                 string pref = "", suff = "";
                 if(i) pref = par.substr(0, i);
                 if(i<par.size()-1) suff = par.substr(i+1);
                 string child = pref+'$'+suff;
                 int pos = pref.size();
                 for(char c='a'; c<='z'; c++){
                       if(c!=par[i]){
                            child[pos]=c;
                            if(distance.count(child)){
                                 if(distance[child] > 1 + distance[par]){
                                     distance[child] =  1 + distance[par];
                                     parent[child].clear();
                                     parent[child].push_back(par);
                                     q.push(child);
                                 }
                                 else if(distance[child] == 1 + distance[par]){
                                     parent[child].push_back(par);
                                 }
                            }
                       }
                 }
             }
         }
         location(last, path);
         for(int i=0; i<ans.size(); i++) reverse(ans[i].begin(), ans[i].end());
         return ans;
    }
};
