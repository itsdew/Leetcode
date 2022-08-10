//Author: Devendra Uraon
#include <bits/stdc++.h>
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define forloop for(ll i = 0; i < n; ++i)
#define input cin >>
#define print cout <<
#define MAX 2147000000
#define MOD 998244353LL
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	ll T; cin >> T;
    while(T--){
        ll n; input n;
        vl vec(n);
        ll mx = 0;
        forloop{
            input vec[i];
            mx = max(mx, vec[i]);
        }
        ll l = 0, r = LLONG_MAX;
        ll ans = LLONG_MAX;
        while(l <= r){
            ll m = (l + r) / 2;
            ll one = (m + 1) / 2;
            ll two = m / 2;
            vl v;
            forloop{
                v.push_back(mx - vec[i]);
            }
            forloop{
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
        l = 0, r = LLONG_MAX;
        while(l <= r){
            ll m = (l + r) / 2;
            ll one = (m + 1) / 2;
            ll two = m / 2;
            vl v;
            forloop{
                v.push_back(mx + 1 - vec[i]);
            }
            forloop{
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
        print ans << "\n";
    }
}
