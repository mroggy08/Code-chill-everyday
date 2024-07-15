#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 2e5+3;
const int lg = 19;
int n,q,u,v,h[N],f[N],up[N][lg];
std::vector<int> a[N];
void dfs(int u){
	for (int v : a[u]){
		if (v==up[u][0]) continue;
		up[v][0] = u;
		h[v]=h[u]+1;
		f[v]=f[u]+1;
		f1(j,1,18) up[v][j]=up[up[v][j-1]][j-1];
		dfs(v);
	}
}
int lca(int u, int v){
    if (h[u]!=h[v]) {
        if (h[u]<h[v]) swap(u,v);
        int k = h[u]-h[v];
        for (int j = 0; (1<<j)<=k; j++){
            if (k>>j & 1) u = up[u][j];
        }
    }
    if (u==v) return u;
    int k = __lg(h[u]);
    for (int j = k; j >= 0; j--){
        if (up[u][j]!=up[v][j]){
            u = up[u][j];
            v = up[v][j];
        }
    }
    return up[u][0];
}
// int lca(int u, int v) {
//     if (h[u] != h[v]) {
//         if (h[u] < h[v]) swap(u, v);
//         int k = h[u] - h[v];
//         for (int j = 0; (1 << j) <= k; ++j)
//             if (k >> j & 1)
//                 u = up[u][j];
//     }
//     if (u == v) return u;
//     int k = __lg(h[u]);
//     for (int j = k; j >= 0; --j)
//         if (up[u][j] != up[v][j])
//             u = up[u][j], v = up[v][j];
//     return up[u][0];
// }
int kc(int u, int v){
	return f[u]+f[v]-2*f[lca(u,v)];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    cin >> n >> q;
    f1(i,1,n-1){
    	cin >> u >> v;
    	a[u].pb(v);a[v].pb(u);
    }
    dfs(1);
    while (q--){
    	cin >> u >> v;
    	cout << kc(u,v) << '\n';
    }
    return 0;
}
