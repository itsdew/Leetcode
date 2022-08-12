//Author: Devendra Uraon
#include <bits/stdc++.h>
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define forloop for(int i = 0; i < n; ++i)
#define input cin >>
#define print cout <<
#define MAX 2147000000
#define MOD 998244353LL
using namespace std;

ll modpow(ll a, ll b){
    ll ans = 1;
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
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n; input n;
    vi vec(n);
    map<int, vi> m;
    forloop{
        input vec[i];
        m[vec[i]].push_back(i);
    }
    vp v;
    for(auto& i : m){
        if(i.second.size() == 1) continue;
        auto& s = i.second;
        sort(s.begin(), s.end());
        v.push_back({s.front(), s.back()});
    }
    int sum = 0;
    sort(v.begin(), v.end());
    int l = -1, r = -1, cnt = 1;
    if(v.size()){
        l = v[0].first;
        r = v[0].second;
    }
    for(int i = 0; i < (int)v.size(); ++i){
        if(v[i].first > r){
            sum += r - l + 1;
            l = v[i].first;
            r = v[i].second;
            cnt++;
        }
        else{
            //l = min(l, v[i].first);
            r = max(r, v[i].second);
        }
    }
    sum += r - l + 1;
    print modpow(2, n - 1 - sum + cnt);
}
