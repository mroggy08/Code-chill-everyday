#include <bits/stdc++.h>
#define f1(i,n,m) for (int i=n; i<=m; i++)
#define file(name)  if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }
#define ll long long
#define fi first
#define se second
#define ii pair<ll,int>
using namespace std;
const int N = 111;
const int oo = 1e9+7;
int n,d[N][N],vis[N],x;
ll ans;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	file("1");
	cin >> n;
	f1(i,1,n) f1(j,1,n) {
		cin >> d[i][j];
		if (!d[i][j]) d[i][j] = oo;
	}
	f1(k,1,n) f1(i,1,n) f1(j,1,n) d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
	vis[x=1] = 1;
	while (1){
		int y = 0, mi = oo-1;
		f1(z,2,n-1){
			if (d[x][z]<mi && !vis[z]){
				mi = d[x][z];
				y = z;
			}
		}
		if (!y) break;
		ans += d[x][y]; vis[x=y] = 1;
	}
	ans+=d[x][n]; cout << ans;
    return 0;
}



