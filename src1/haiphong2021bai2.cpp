#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pri priority_queue <pii,vii, greater<pii>>
#define pb push_back
#define f1(i, l, r) for (int i = l; i <= r; ++i)
#define fd(i,n) for (int i = 0; i < (n); i++)
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define twt int T;cin>>T;while(T--)
 
const int maxn = 1000000;
const ll mo = 1000000007;
 
using namespace std;
int n,a[maxn+3],x;
int f[maxn+3],dp[maxn+3],u,v,q,mx;
bool nt(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
		if (n%i==0)
			return 0;
		return n > 1;
}
void sang()
{
	f[0] = f[1] = 1;
	for (int i = 2; i*i <= maxn; i++)
		if (!f[i]) for (int j = i*i; j <= maxn; j+=i) f[j] = 1;
}
bool ch2(int n)
{
	for (int k = 1; k <= 9; k+=2)
		if (nt(n*10+k)) return 1;
	return 0;
}
bool ch3(int n)
{
	n/=10;
	while (n>1)
	{
		if (nt(n)==0) return 0;
		n/=10;
	}
	return (n<1);
}
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("INP.INP","r",stdin);
    freopen("OUT.OUT","w",stdout);
    #endif // ONLINE_JUDGE
    faster;
    cin >> n;
    f1(i,1,n) 
    {
    	cin >> a[i];
    	mx = max(mx,a[i]);
    }
    if (mx <= 1e6)
    {
    	sang();
    	f1(i,1,n)
    	{
    		if (!f[a[i]])
    		{
    			if (ch2(a[i]) && ch3(a[i]))
    				dp[i] = dp[i-1] + 1;
    			else dp[i] = dp[i-1];
    		}
    		else dp[i] = dp[i-1];
    	}
  		cin >> q;
  		while (q--)
  		{
  			cin >> u >> v;
  			cout << dp[v] - dp[u-1] << '\n';
  		}
    }
    else 
    {
    	sang();
    	f1(i,1,n)
    	{
    		if (a[i]<=1e6)
    		{
	    		if (!f[a[i]])
	    		{
	    			if (ch2(a[i]) && ch3(a[i]))
	    				dp[i] = dp[i-1] + 1;
	    			else dp[i] = dp[i-1];
	    		}
	    		else dp[i] = dp[i-1];	
    		}
    		else
    		{
    			if (nt(a[i]))
    			{
    				if (ch2(a[i]) && ch3(a[i]))
	    				dp[i] = dp[i-1] + 1;
	    			else dp[i] = dp[i-1];
    			}
    			else dp[i] = dp[i-1];
    		}
    	}
    	cin >> q;
    	while (q--)
    	{
    		cin >> u >> v;
    		cout << dp[v] - dp[u-1] << '\n';
    	}
    }
    return ( 0 ^ 0 );
}
 