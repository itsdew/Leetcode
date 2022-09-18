// 2022-05-02
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
#define MOD 1000000007
using namespace std;

int main(){
    fastio;
	int n;
    cin >> n;
    vl A(n);
    for(int i{0}; i < n; ++i){
        cin >> A[i];
    }
    ll ans{LLONG_MAX};
    for(int i{0}; i < n; ++i){
        ll sum{0};
        vl B(n);
        for(int j{i - 1}; j >= 0; --j){
            B[j] = (B[j + 1] + A[j] ) / A[j] * A[j]; 
            sum += (B[j + 1] + A[j] ) / A[j];
        }
        for(int j{i + 1}; j < n; ++j){
            B[j] = (B[j - 1] + A[j] ) / A[j] * A[j]; 
            sum += (B[j - 1] + A[j] ) / A[j];
        }
        ans = min(ans, sum);
    }
    cout << ans;
}
