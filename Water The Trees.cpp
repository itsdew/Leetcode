// 2022-05-24
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
	int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi vec(n);
        for(int i{0}; i < n; ++i){
            cin >> vec[i];
        }
        if(n & 1){
            cout << "NO\n";
            continue;
        }
        vi v;
        sort(vec.begin(), vec.end());
        for(int i{0}; i < n / 2; ++i){
            v.push_back(vec[i]);
            v.push_back(vec[n - 1 - i]);
        }
        bool flag = true;
        for(int i{0}; i < n; ++i){
            if(v[i] > v[(i + 1) % n] && v[i] > v[(i + n - 1) % n]) continue;
            if(v[i] < v[(i + 1) % n] && v[i] < v[(i + n - 1) % n]) continue;
            flag = false;
        }
        if(flag){
            cout << "YES\n";
            for(auto& i : v) cout << i << " ";
            cout << "\n";
        }
        else cout << "NO\n";
    }
}
