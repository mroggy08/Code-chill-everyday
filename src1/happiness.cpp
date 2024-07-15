#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e5+3;
ii a[N];
int n,m;
ll ans,f[N];
bool cmd(ii a, ii b)
{
	return a.fi > b.fi;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("INP.INP","r",stdin);
    freopen("OUT.OUT","w",stdout);
    #endif // ONLINE_JUDGE
    cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> a[i].fi >> a[i].se;
    sort(a+1,a+m+1,cmd);
	for (int i = 1; i <= m; i++) f[i] = f[i-1] + a[i].fi;
		ans = f[min(n,m)];
	for (int i = 1; i <= m; i++)
	{
		int l = 1, r = m, kq = 0;
		while (l<=r)
		{
			int mid = (r+l)>>1;
			if (a[mid].fi >= a[i].se)	
			{
				kq = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		if (kq < i) 
		{
			kq = min(kq,n-1);
			ans = max(ans, f[kq] + a[i].fi + 1LL*(n-kq-1)*a[i].se);
		}
		else if (kq <= n)
			ans = max(ans, f[kq] + 1LL*(n-kq)*a[i].se);
	}
	cout << ans;
    return ( 0 ^ 0);
}