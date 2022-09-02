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
        int n, q;
        cin >> n >> q;
        vp vec(n + 1);
        for(int i{1}; i <= n; ++i){
            cin >> vec[i].first >> vec[i].second;
        }
        sort(vec.begin(), vec.end());
        vl preSum(n + 1);
        for(int i{1}; i <= n; ++i){
            preSum[i] = 1LL * vec[i].first * vec[i].second;
            preSum[i] += preSum[i - 1];
        }
        while(q--){
            int h1, w1, h2, w2;
            cin >> h1 >> w1 >> h2 >> w2;
            ll ans{0};
            auto it1 = lower_bound(vec.begin(), vec.end(), make_pair(h1 + 1, w1 + 1)) - vec.begin();
            auto it2 = upper_bound(vec.begin(), vec.end(), make_pair(h2 - 1, w2 - 1)) - vec.begin();
            while(it2 == n + 1 || (vec[it2].first == h2 || (vec[it2].second == w2))) it2--;
            cout << preSum[it2] - preSum[it1 - 1] << "\n";            
        }
    }
}

