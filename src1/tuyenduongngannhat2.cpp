#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define vi vector<int>
#define vii vector<ii>
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
#define bit(i,x) ((x>>i)&1)
#define bp __builtin_popcount
#define inf INT_MAX
using namespace std;
const int N = 1e6+3;
int n,m,q,u,v,w;
ll  f[1003][1003];
ll minn(ll a, ll b)
{
	if (a<b) return a;
	return b;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define task "task"
    if (fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> m >> q;
    f1(i,1,n) f1(j,1,n) f[i][j] = 1e18;
    f1(i,1,n) f[i][i] = 0;
    while (m--)
    {
    	cin >> u >> v >> w;
    	f[u][v] = f[v][u] = minn(f[u][v],w);
    }
    f1(k,1,n) f1(i,1,n) f1(j,1,n) f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
    while (q--)
    {
    	cin >> u >> v;
    	cout << (f[u][v]!=1e18 ? f[u][v] : -1) << '\n';
    }
    return 0;
}
