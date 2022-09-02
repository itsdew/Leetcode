// 2022-08-30
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main() {
	fastio;
    int t;
    cin >> t;
    while(t--){
        vector<vi> g(1001);
        int n, q;
        cin >> n >> q;
        for(int i{1}; i <= 1000; ++i){
            g[i].push_back(0);
        }
        for(int i{0}; i < n; ++i){
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
        }
        vector<vi> preSum = g;
        for(int i{1}; i <= 1000; ++i){
            sort(g[i].begin(), g[i].end());
        }
        for(int i{1}; i <= 1000; ++i){
            for(int j{1}; j < (int)g[i].size(); ++j){
                preSum[i][j] += preSum[i][j - 1];
            }
        }
        while(q--){
            int h1, w1, h2, w2;
            cin >> h1 >> w1 >> h2 >> w2;
            ll ans{0};
            for(int i{h1 + 1}; i < h2; ++i){
                int l = upper_bound(g[i].begin(), g[i].end(), w1) - g[i].begin();
                int r = lower_bound(g[i].begin(), g[i].end(), w2) - g[i].begin();
                ans += 1LL * i * (preSum[i][r - 1] - preSum[i][l - 1]);
            }
            cout << ans << "\n";
        }
    }
}

