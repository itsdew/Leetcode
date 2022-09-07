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
int dp[5001][5001]{};

int main(){
    fastio;
	int t;
    cin >> t;
    while(t--){
        int n;
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
        ll ans{0};
        for(int i{0}; i < n; ++i){
            for(int j{0}; j < n; ++j){
                dp[i][j] = graph2[i].end() - upper_bound(graph2[i].begin(), graph2[i].end(), j);
            }
        }
        for(int j{0}; j < n; ++j){
            for(int i{1}; i < n; ++i){
                dp[i][j] += dp[i - 1][j];
            }
        }
        for(int a{0}; a < n; ++a){
            for(auto c : graph[a]){
                // for(int j{a + 1}; j < c; ++j){
                //     ans += dp[j][c];
                // }          
                ans += dp[c - 1][c] - dp[a][c];       
            }   
        }
        cout << ans << "\n";
    }
}
