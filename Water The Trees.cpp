#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
#define pw(x) (1ll << (x))
#define sz(x) (int)x.size()
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const int MAXN = 1e6 + 1e5;;
const int M = pw(16);
const long long mod = 998244353;
const int N = 3e5;
const int inf = 1e9;
template <typename T> void vout(T s){cout << s << endl;exit(0);}

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll buben = 500;

vector <int> dv[N + 10];

void solve() {       
    ll n;
    cin >> n;
    ll s = 0;
    vector <ll> c;
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) dv[j].p_b(i);
    }

    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        c.p_b(a - b);
        s += b;
    }
    sort(all(c));
    reverse(all(c));
    vector <ll> f(n + 1);
    f[0] = s;
    for (int i = 1; i <= n; i++) f[i] = f[i - 1] + c[i - 1];
    ll q;
    cin >> q;
    map <pii, ll> mp;    

    for (int x = 1; x <= buben; x++) {
        for (int c = 0; c * x <= n; c++) {            
            for (auto y : dv[n - c * x]) {                              
                mp[{x, y}] = max(mp[{x, y}], f[c * x]);  
            }            
        }
    }

    while (q--) {
        ll ans = -1;
        ll x, y;
        cin >> x >> y;
        if (x >= buben) {
            for (int c = 0; c * x <= n; c++) if ((n - c * x) % y == 0) {
                ans = max(ans, f[c * x]);
            }
            cout << ans << "\n";
        }else{
            ll ans = -1;
            if (n % x == 0) ans = f[n];
            if (mp.find({x, y}) == mp.end()) {
                cout << ans << "\n";;
            }else {
                cout << max(ans, mp[{x, y}]) << "\n";
            }
        }        
    }
    cout << "\n";
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t;  

    #ifdef Local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        cin >> t;
    #endif  
    // cin >> t;   

    while (t--) {
        solve();
    }


    return 0;
}  
