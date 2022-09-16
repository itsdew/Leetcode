// 2022-07-13
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

int main() {
	fastio;
	int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vl vec(n);
        for(int i{0}; i < n; ++i){
            cin >> vec[i];
        }
        vector<vl> dp(32, vl(n + 1, -LLONG_MAX / 2));
        dp[0][0] = 0;
        for(int i{0}; i < 32; ++i){
            for(int j{0}; j < n; ++j){
                dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + (vec[j] >> i) - k);
                if(i > 0) dp[i][j + 1] = max(dp[i - 1][j] + (vec[j] >> i), dp[i][j + 1]);
            }
        }
        ll ans{-LLONG_MAX};
        for(int i{0}; i < 32; ++i){
            ans = max(ans, dp[i][n]);
        }
        cout << ans << "\n";
    }
}
