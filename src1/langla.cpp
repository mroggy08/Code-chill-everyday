#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,int> ii;
const int N = 2e5+5;
const int lg = 17;
int n,u,v,q,b,c,d,h[N],up[N][lg+2];
vector<ii> a[N];
ll w,f[N];
void dfs(int u){
    for (ii e : a[u]){
        if (e.se==up[u][0]) continue;
        h[e.se] = h[u] + 1;
        f[e.se] = f[u] + e.fi;
        up[e.se][0] = u;
        for (int j = 1; j <= lg; j++){
            up[e.se][j] = up[up[e.se][j-1]][j-1];
        }
        dfs(e.se);
    }
}
int lca(int u, int v){
    if (h[u]!=h[v]){
        if (h[u]<h[v]) swap(u,v);
        int k = h[u]-h[v];
        for (int j = 0; (1<<j) <= k; j++){
            if (k>>j & 1){
                u = up[u][j];
            }
        }
    }
    if (u==v) return u;
//    int k = __lg(h[u]);
    for (int j = __lg(h[u]); j >= 0; j--){
        if (up[u][j]!=up[v][j]){
            u = up[u][j]; v = up[v][j];
        }
    }
    return up[u][0];
}
int kc(int a, int b){
    return f[a]+f[b]-2*f[lca(a,b)];
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++){
        cin >> u >> v >> w;
        a[u].pb({w,v});
        a[v].pb({w,u});
    }
    dfs(1);
    cin >> q;
    while (q--){
        cin >> b >> c >> d;
        cout << min({kc(b,lca(c,d)) + kc(c,lca(c,d)) + kc(d,lca(c,d)),
                    kc(b,lca(b,d)) + kc(c,lca(b,d)) + kc(d,lca(b,d)),
                    kc(b,lca(b,c)) + kc(c,lca(b,c)) + kc(d,lca(b,c))}) << '\n';
    }

    return 0;
}
