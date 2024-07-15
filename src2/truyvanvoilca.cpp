#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 3e5+3;
int n,u,v,q,h[N],up[N][19],ans[N][19];
std::vector<int> a[N];
void dfs(int u){
	for (int v : a[u]){
		if (v==up[u][0]) continue;
		up[v][0] = u;
		h[v]=h[u]+1;
//		f[v]=f[u]+1;
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
    int LG = __lg(n) + 2;
//    cout << LG << '\n';
    f1(i,1,n) ans[i][0] = i;
    f1(j,1,LG) for (int i = 1; i + (1<<j) -1 <= n; i++){
    	ans[i][j] = lca(ans[i][j-1],ans[i+(1<<(j-1))][j-1]);
    }
//    cout << lca(2,3) << '\n';
    while (q--){
    	cin >> u >> v;
    	int k = __lg(v-u+1);
    	cout << lca(ans[u][k],ans[v-(1<<k)+1][k]) << '\n';
    }
    return 0;
}
