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


int main()
{
	ll n,q;
	cin>>n;
	ll arr[n];
	for(ll i=0;i<n;i++)
		cin>>arr[i];
	cin>>q;
	while(q--)
	{
		ll l,r,c=0,d=0,a=0,b=0;
		cin>>l>>r;
		c = *min_element(arr+l,arr+r+1);
		d = *max_element(arr+l,arr+r+1);
		if(l>0)
		a = *max_element(arr,arr+l);
		if(r<n-1)
		b = *max_element(arr+r+1,arr+n);
		float ans1 = (c+d)/2;
		float ans2 = (c+max(a,b));
		cout<<fixed<<std::setprecision(1)<<max(ans1,ans2)<<endl;
	}
	return 0;
}
