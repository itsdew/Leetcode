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
    vp vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first;
        vec[i].second = i;
    }
    sort(vec.begin(), vec.end());
    vl A(n + 1);
    vl B(n + 1);
    for(int i{1}; i <= n; ++i){
        A[i] = vec[i - 1].first;
        A[i] += A[i - 1];
        B[i] = vec[i - 1].second + 1;
        B[i] += B[i - 1];  
    }
    ll mx{0};
    ll cost{0};
    for(ll i{1}; i <= n; ++i){
        if(A[i] + B[i] * i <= s){
            mx = i;
            cost = A[i] + B[i] * i;
        }
    }
    cout << mx << " " << cost;
}
