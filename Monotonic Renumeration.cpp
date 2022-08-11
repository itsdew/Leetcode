#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<math.h>
#include<unordered_map>
#include<queue>
#include<stack>
#include<set>
#include<unordered_set>
#include<iomanip>

#define ll long long
#define ull unsigned long long
#define mp make_pair
#define ff first
#define ss second
#define mloop(i) for(auto i=m.begin();i!=m.end();i++)
#define sloop(i) for(auto i=s.begin();i!=s.end();i++)
#define pb push_back

using namespace std;
vector<bool> prime(200002,true);
void seive(long mx)
{
	prime[0]=prime[1]=false;
	for(long i=2;i<=mx;i++)
	{
		for(long j=2;(ll)j*j<=i;j++)
		{
			if(i%j == 0)
			{
				prime[i]=false;
				break;
			}
		}
	}
}
ll power(ll i,int p)
{
	ll ans=1;
	while(p)
	{
		if(p & 1)
			ans = ans*i;
		i = i*i;
		p/=2;
	}
	return ans;
}
ll merge(ll a,ll b)
{
	return max(a,b);
}
ll merge1(ll a,ll b)
{
	return min(a,b);
}
void build(ll segmentTree[],ll l,ll r,ll idx,ll arr[])
{
	if(l == r)
	{
		segmentTree[idx] = arr[l];
		//cout<<idx<<" ("<<l<<" "<<r<<") "<<segmentTree[idx]<<endl;
	}
	else
	{
		ll mid = (l+r)/2;
		build(segmentTree,l,mid,2*idx+1,arr);
		build(segmentTree,mid+1,r,2*idx+2,arr);
		segmentTree[idx] = merge(segmentTree[2*idx+1] , segmentTree[2*idx+2]);
		//cout<<idx<<" ("<<l<<" "<<r<<") "<<segmentTree[idx]<<endl;
	}
}
void build1(ll segmentTree1[],ll l,ll r,ll idx,ll arr[])
{
	if(l == r)
	{
		segmentTree1[idx] = arr[l];
		//cout<<idx<<" ("<<l<<" "<<r<<") "<<segmentTree1[idx]<<endl;
	}
	else
	{
		ll mid = (l+r)/2;
		build1(segmentTree1,l,mid,2*idx+1,arr);
		build1(segmentTree1,mid+1,r,2*idx+2,arr);
		segmentTree1[idx] = merge1(segmentTree1[2*idx+1] , segmentTree1[2*idx+2]);
		//cout<<idx<<" ("<<l<<" "<<r<<") "<<segmentTree1[idx]<<endl;
	}
}
ll queries(ll segmentTree[],ll l,ll r,ll LL,ll RR, ll idx)
{
	if(LL<=l && RR>=r)
		return segmentTree[idx];
	else if(RR<=(l+r)/2)
		return queries(segmentTree,l,(l+r)/2,LL,RR,2*idx+1);
	else if(LL>(l+r)/2)
		return queries(segmentTree,(l+r)/2+1,r,LL,RR,2*idx+2);
	else
		return merge(queries(segmentTree,l,(l+r)/2,LL,RR,2*idx+1),queries(segmentTree,(l+r)/2+1,r,LL,RR,2*idx+2));
}
ll queries1(ll segmentTree1[],ll l,ll r,ll LL,ll RR, ll idx)
{
	if(LL<=l && RR>=r)
		return segmentTree1[idx];
	else if(RR<=(l+r)/2)
		return queries1(segmentTree1,l,(l+r)/2,LL,RR,2*idx+1);
	else if(LL>(l+r)/2)
		return queries1(segmentTree1,(l+r)/2+1,r,LL,RR,2*idx+2);
	else
		return merge1(queries1(segmentTree1,l,(l+r)/2,LL,RR,2*idx+1),queries1(segmentTree1,(l+r)/2+1,r,LL,RR,2*idx+2));
}
int main()
{
	ll n,q;
	cin>>n;
	ll arr[n];
	for(ll i=0;i<n;i++)
		cin>>arr[i];
	ll segmentTree[4*n],segmentTree1[4*n];
	build(segmentTree,0,n-1,0,arr);
	build1(segmentTree1,0,n-1,0,arr);
	cin>>q;
	while(q--)
	{
		ll l,r,qans=0,lans=0,rans=0,mini=0;
		cin>>l>>r;
		 qans = queries(segmentTree,0,n-1,l,r,0);
		if(l>0)
		 lans = queries(segmentTree,0,n-1,0,l-1,0);
		if(r<n-1)
		 rans = queries(segmentTree,0,n-1,r+1,n-1,0);
		 mini = queries1(segmentTree1,0,n-1,l,r,0);
		float ans = max((float)(mini+qans)/2,(float)(mini + max(lans,rans)));
		cout<<fixed<<setprecision(1)<<ans<<endl;
	}
	return 0;
}
