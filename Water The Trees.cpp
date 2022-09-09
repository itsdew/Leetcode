// 2022-03-14
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
        vl A(n), B(n);
        for(int i{0}; i < n; ++i){
            cin >> A[i];
        }
        ll sum{0};
        for(int i{0}; i < n; ++i){
            cin >> B[i];
            sum += B[i];
        }
        map<int, vl> m;
        for(int i{0}; i < n; ++i){
            m[A[i]].push_back(B[i]);
        }
        int mx{0};
        for(auto& i : m){
            auto& v = i.second;
            sort(v.begin(), v.end());
            mx = max(mx, (int)v.size());
            for(int j{1}; j < (int)v.size(); ++j){
                v[j] += v[j - 1];
            }
        }
        vl ans(n);
        for(int i{1}; i <= mx; ++i){
            ll k = sum;
            for(auto& j : m){
                int s = (int)j.second.size();
                if(i > s){
                    k -= j.second.back();
                    continue;
                }
                int d = s % i;
                if(d == 0) continue;
                k -= j.second[d - 1];
            }
            ans[i - 1] = k;
        }
        for(int i{0}; i < n; ++i){
            if(i >= mx) cout << 0 << " ";
            else cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
