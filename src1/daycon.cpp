#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define f1(i,n,m) for (int i = n; i <= m; i++)
#define fz(i,n) for (int i = 0; i < n; i++)
#define __ThanhDat int main
using namespace std;
const int N = 1e5+3;
const ll mo = 1000000007;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const ll inf = 1e18;
int n,a[N];
ll f[N];
ll dp(int id)
{
	if (id==1) return a[1];
	if (id > n) return 0;
	if (f[id]!=-inf) return f[id];
	ll kq = max(dp(id+1),dp(id+1) + a[id]);
	return	f[id] = kq;
}
__ThanhDat()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    #define task "inp"
    if (fopen(task".inp","r")) {
    	freopen(task".inp","r",stdin);
    	freopen(task".out","w",stdout);
    }
    cin >> n;
    f1(i,1,n) cin >> a[i];
    f1(i,1,n) f[i] = -inf;
    f1(i,1,n) cout << dp(i) << ' ';
    return 0;
}