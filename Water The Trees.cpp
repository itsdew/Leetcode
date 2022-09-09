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

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}
int main(){
    fastio;
    int n;
    cin >> n;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    vi post(n);
    post[n - 1] = vec[n - 1];
    for(int i{n - 2}; i >= 0; --i){
        post[i] = gcd(vec[i], post[i + 1]);
    }
    vi pre(n);
    post[0] = vec[0];
    for(int i{1}; i < n; ++i){
        pre[i] = gcd(vec[i], pre[i - 1]);
    }
    int ans{0};
    for(int i{0}; i < n; ++i){
        if(i == 0){
            ans = max(ans, post[1]);
        }
        else if(i == n -1){
            ans = max(ans, pre[n - 2]);
        }
        else{
            ans = max(ans, gcd(pre[i - 1], post[i + 1]));
        }
    }
    cout << ans;
}
