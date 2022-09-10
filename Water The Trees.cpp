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
    vl vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    int l{0}, r{n};
    int mx{0};
    int mxSum{0};
    while(l <= r){
        int m{(l + r) / 2};
        vl copy = vec;
        for(int i{0}; i < n; ++i){
            copy[i] += 1LL * (i + 1) * m;
        }
        sort(copy.begin(), copy.end());
        ll sum{0};
        for(int i{0}; i < m; ++i){
            sum += copy[i];
        }
        if(sum <= s){
            l = m + 1;
            if(mx < m){
                mx = m;
                mxSum = sum;
            }
        }
        else r = m - 1;
    }
    cout << mx << " " << mxSum;
}
