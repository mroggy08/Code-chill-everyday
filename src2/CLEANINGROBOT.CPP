#include <bits/stdc++.h>
#define f1(i,n,m) for (int i=n; i<=m; i++)
#define fi first
#define se second
#define pb push_back
#define ii pair<int,int>
#define lli pair<ll,int>
#define VI vector<int>
#define VII vector<ii>
#define VLLI vector<lli>
#define ALL(a) a.begin(),a.end()
using namespace std;
const int N = 1e4+4;
int n,q,h[N],f[N],up[N][10],lg=10;
VII a[N];
void dfs(int u){
    for (ii e : a[u]){
        if (e.se==up[u][0]) continue;
        h[e.se] = h[u] + 1;
        f[e.se] = f[u] + e.fi;
        up[e.se][0] = u;
        for(int j = 1; j < 10; j++) up[e.se][j] = up[up[e.se][j-1]][j-1];
        dfs(e.se);
    }
}
int lca(int u, int v){
    if (h[u]!=h[v]){
        if (h[u]<h[v]) swap(u,v);
        int k = h[u]-h[v];
        for (int j = 0; (1<<j) <= k; j++) if (k>>j&1) u = up[u][j];
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
int kc(int u, int v){
    return f[u] + f[v] - 2*f[lca(u,v)];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    f1(i,1,n-1){
        int u,v,w;
        cin >> u >> v >> w;
        a[u].pb({w,v});
        a[v].pb({w,u});
    }
    dfs(1);
    while (q--){
        int u,v;
        cin >> u >> v;
         cout << kc(u,v) << '\n';
    }
    return 0;
}
