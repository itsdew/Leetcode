// Snippets: https://github.com/prabhavdogra/CPSnippets
#include <bits/stdc++.h>
using namespace std; 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#ifdef prabhav_
    // #define TERMINAL
    #include "Headers/debug.cpp"
#else
    #define d(...) 0
    #pragma GCC optimize("O3")
    #pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#endif

#define int long long int
#define ld long double
#define forp(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define sz(a) (int)a.size()
#define endl '\n'
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define uniq(a) (a).erase(unique(all(a)), (a).end())
#define fix(f, n) fixed << setprecision(n) << f
#define setbits(x) __builtin_popcount(x)
#define setbitsll(x) __builtin_popcountll(x)
#define MSB(n) (31 - __builtin_clz(n))
constexpr int64_t INF = 2e18;
constexpr int64_t M = 1 ? 1e9 + 7 : 998'244'353;
int ceil(int a, int b) { return (a + b - 1) / b; }


void prabhav() {
    int n, ans = 1;
    string s;
    cin >> n >> s;
    n *= 2;
    auto rec = [&] (const auto &self, int start, int end) {
        if(start > end) return;
        ans++;
        int cstart = start, cnt = 0;
        for(int i = start; i < end + 1; i++) {
            if(s[i] == '(') cnt++;
            else cnt--;
            if(cnt == 0) {
                self(self, cstart + 1, i - 1);
                cstart = i + 1;
            }
        }
    };
    int cnt = 0, start = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '(') cnt++;
        else cnt--;
        if(cnt == 0) {
            rec(rec, start + 1, i - 1);
            start = i + 1;
        }
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T = 1;
    cin >> T;
    while (T--) {
        prabhav();
    }
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
