#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e6+3;
ii a[N];
int n,f[N],l1,pos,p,ans,m,v;
int tknp(int le, int ri,int val)
{
	int kq = -1;
	while (le<=ri)
	{
		int mid = (ri+le)>>1;
		if (a[mid].fi > val)
		{
			kq = mid;
			ri = mid - 1;
		}
		else le = mid + 1;
	}
	return kq;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;
    sort(a+1,a+n+1);
	for (int i = 1; i <= n; i++)
		f[i] = f[i-1] + a[i].se;
	pos = a[1].fi;
	l1 = 1;
	while (l1<=n)
	{
        v = pos + m*2;
		p = tknp(1,n,v);
        if (p!=-1)
		{
		    ans = max(ans,f[p-1] - f[l1-1]);
		    l1 = p;
		    pos = a[p].fi;
		}
		else {
			ans = max(ans,f[n] - f[l1-1]);
            break;
		}
	}
	cout << ans;
    return ( 0 ^ 0);
}

