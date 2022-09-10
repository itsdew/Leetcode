// 2022-04-07
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
	int n; ll s;
    cin >> n >> s;
    vl pre(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> pre[i];
        pre[i] += pre[i - 1];
    }
    ll mx{0};
    ll cost{0};
    for(ll i{1}; i <= n; ++i){
        if(pre[i] + i * (i + 1) / 2 * i <= s){
            mx = i;
            cost = pre[i] + i * (i + 1) / 2 * i;
        }
    }
    cout << mx << " " << cost;
}
