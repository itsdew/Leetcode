//Question: https://codeforces.com/contest/1661/problem/C
//Author: Devendra Uraon
#include <bits/stdc++.h>
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
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n; cin >> n;
    vi C(n);
    for(int i = 0; i < n; ++i){
        cin >> C[i];
    }
    vector<string> vec(n);
    for(int i = 0; i < n; ++i){
        cin >> vec[i];
    }
    vector<vl> dp(n, vl(2, MAX));
    dp[0][0] = 0;
    dp[0][1] = C[0];
    for(int i{1}; i < n; ++i){
        if(dp[i - 1][0] == MAX && dp[i - 1][1] == MAX){
            cout << -1;
            return 0;
        }
        string p = vec[i - 1];
        string pr = p;
        reverse(pr.begin(), pr.end());
        string r = vec[i];
        reverse(r.begin(), r.end());
        if(vec[i] >= p){
            dp[i][0] = min(dp[i][0], dp[i - 1][0]);
        }
        if(vec[i] >= pr){
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        }
        if(r >= p){
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + C[i]);
        }
        if(r >= pr){
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + C[i]);
        }
    }
    ll ans = min(dp[n - 1][0], dp[n - 1][1]);
    if(ans == MAX) cout << -1;
    else{
        cout << ans;
    }
}
