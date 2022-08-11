// 2022-03-26
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

ll modpow(ll a, ll b){
    ll ans{1};
    while(b > 0){
        if(b % 2){
            ans *= a;
            ans %= MOD;
        }
        a *= a;
        b /= 2;
        a %= MOD;
    }
    return ans;
}

int main(){
    fastio;
	int n;
    cin >> n;
    vi vec(n);
    map<int, vi> m;
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
        m[vec[i]].push_back(i);
    }
    vp v;
    for(auto& i : m){
        if(i.second.size() == 1) continue;
        auto& s = i.second;
        sort(s.begin(), s.end());
        v.push_back({s.front(), s.back()});
    }
    int sum{0};
    sort(v.begin(), v.end());
    int l{-1}, r{-1};
    int cnt{1};
    if(v.size()){
        l = v[0].first;
        r = v[0].second;
    }
    for(int i{1}; i < (int)v.size(); ++i){
        if(v[i].first > r + 1){
            sum += r - l + 1;
            l = v[i].first;
            r = v[i].second;
            cnt++;
        }
        else{
            r = max(r, v[i].second);
        }
    }
    sum += r - l + 1;
    cout << modpow(2, n - 1 - sum + cnt);
}
