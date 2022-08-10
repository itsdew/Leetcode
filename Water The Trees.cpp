// 2022-04-08
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
#define MOD 998244353LL
using namespace std;

int main(){
    fastio;
	int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vl vec(n);
        ll mx{0};
        for(int i{0}; i < n; ++i){
            cin >> vec[i];
            mx = max(mx, vec[i]);
        }
        ll l{0}, r{MAX};
        ll ans{MAX};
        while(l <= r){
            ll m{(l + r) / 2};
            ll one = (m + 1) / 2;
            ll two = m / 2;
            vl v;
            for(int i{0}; i < n; ++i){
                v.push_back(mx - vec[i]);
            }
            for(int i{0}; i < n; ++i){
                ll k = v[i] / 2;
                v[i] -= min(k, two) * 2;
                two -= min(k, two);
            }
            if(one >= accumulate(v.begin(), v.end(), 0LL)){
                r = m - 1;
                ans = min(ans, m);
            }
            else{
                l = m + 1;
            }
        }
        l = 0, r = MAX;
        while(l <= r){
            ll m{(l + r) / 2};
            ll one = (m + 1) / 2;
            ll two = m / 2;
            vl v;
            for(int i{0}; i < n; ++i){
                v.push_back(mx + 1 - vec[i]);
            }
            for(int i{0}; i < n; ++i){
                ll k = v[i] / 2;
                v[i] -= min(k, two) * 2;
                two -= min(k, two);
            }
            if(one >= accumulate(v.begin(), v.end(), 0LL)){
                r = m - 1;
                ans = min(ans, m);
            }
            else{
                l = m + 1;
            }
        }
        cout << ans << "\n";
    }
}
