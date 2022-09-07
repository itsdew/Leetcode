// 2022-05-04
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

vi graph[5000];
vi graph2[5000];
int n;
int ch[4]{};
int ans{0};

void dfs(int L, vi& vec, int k){
    if(L == 4){        
        ans++;
    }
    else{
        if(L == 0 || L == 1){
            for(int i{k + 1}; i < n; ++i){
                ch[L] = i;
                dfs(L + 1, vec, i);
            }
        }
        else if(L == 2){
            for(auto& i : graph[ch[0]]){
                if(i > ch[1]){
                    ch[2] = i;
                    dfs(L + 1, vec, i);
                }
            }
        }
        else if(L == 3){
            for(auto& i : graph2[ch[1]]){
                if(i > ch[2]){
                    ch[3] = i;
                    dfs(L + 1, vec, i);
                }
            }
        }
    }
}



int main(){
    fastio;
	int t;
    cin >> t;
    while(t--){
        ans = 0;
        cin >> n;
        vi vec(n);
        for(int i{0}; i < n; ++i){
            cin >> vec[i];
            graph[i].clear();
            graph2[i].clear();
        }
        for(int i{0}; i < n; ++i){
            for(int j{i + 1}; j < n; ++j){
                if(vec[i] < vec[j]){
                    graph[i].push_back(j);
                }
                if(vec[i] > vec[j]){
                    graph2[i].push_back(j);
                }
            }
        }
        dfs(0, vec, -1);
        cout << ans << "\n";
    }
}
