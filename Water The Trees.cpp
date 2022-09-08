#pragma G++ optimize("Ofast")
#pragma G++ optimize("unroll-loops")
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<functional>
#include<queue>
#include<unordered_map>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<bitset>
#include<iomanip>
#include<numeric>

using namespace std;

using lli = long long;
using pii = pair<lli, lli>;
const int INF = 1e9;
const lli inf = 1e18;
const int maxn = 1e5+5;
int n, m, ans, mx;
int sum[maxn];

struct Node {
	int a, b, c;
	bool operator < (const Node x) const {
		return c<x.c;
	}
} a[maxn];

lli exgcd(lli a, lli b, lli &x, lli &y) {
	if(!b) {
		x = 1;
		y = 0;
		return a;
	}
	
	lli d = exgcd(b, a%b, y, x);
	y = y - a/b*x;
	
	return d;
}
//gcd = exgcd(a, b, x, y)
//x = x*c/gcd;
//y = y*c/gcd;


void solve() {
	cin>>n;
	ans = 0;
	
	for(int i=1; i<=n; ++i) {
		cin>>a[i].a>>a[i].b;
		a[i].c = a[i].b-a[i].a;
		sum[n]+=a[i].a;
	}
	sort(a+1, a+1+n);
	
	mx = n;
	for(int i=n-1; i>=0; --i) {
		sum[i] = sum[i+1]+a[i+1].c;
		if(a[i+1].c>0)	mx = i;
	}
	
//	for(int i=0; i<=n; ++i) {
//		cout<<sum[i]<<' ';
//	}cout<<'\n';
	
	cin>>m;
	
	for(int i=1; i<=m; ++i) {
		lli a, b, x, y;
		cin>>a>>b;
		lli gcd = exgcd(a, b, x, y);
//		cout<<x<<'\n';
		if(n%gcd) {
			cout<<"-1\n";
			continue;
		}
		x = x*n/gcd;
//		a*x  mx
		x+=ceil((1.0*mx/a-x)/(b/gcd))*(b/gcd);
		if(x<0)	x+=b/gcd;
		y = x-b/gcd;
		cout<<max((0<=a*x&&a*x<=n) ? sum[a*x] : -1, (0<=a*y&&a*y<=n) ? sum[a*y] : -1)<<'\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)solve();
	return 0;
}
