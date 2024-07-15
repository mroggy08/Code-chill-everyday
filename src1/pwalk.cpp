#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> ii;
const int N = 1e5+5;
int n,q,u,v,d[N],h[N],par[N][10];
ll w;
vector<ii> a[N];
void dfs(int u){
    for (ii e : a[u]){
        ll dv = e.first;
        int v = e.second;
        if (v==par[u][0]) continue;

        h[v] = h[u] + 1;
        d[v] = d[u] + dv;

        par[v][0] = u;
        for (int j = 1; j < 10; j++)
            par[v][j] = par[par[v][j-1]][j-1];
        dfs(v);
    }
}
int lca(int u, int v){
    if (h[u] != h[v]){
        if (h[u]<h[v]) swap(u,v);

        int k = h[u] - h[v];

        for (int j = 0; (1<<j) <= k; j++){
            if (k>>j &1){
                u = par[u][j];
            }
        }
    }
    if (u==v) return u;

    int k = __lg(h[u]);
    for (int j = k; j>=0; j--){
        if (par[u][j]!=par[v][j]){
            u = par[u][j];
            v = par[v][j];
        }
    }
    return par[u][0];
}
int dist(int u, int v)
{
    int p = lca(u,v);
    return d[u] + d[v] - 2*d[p];
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i < n; i++){
        cin >> u >> v >> w;
        a[u].push_back({w,v});;
        a[v].push_back({w,u});;
    }
    dfs(1);
    while (q--){
        cin >> u >> v;
        cout << dist(u,v) << '\n';
    }
    cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";
    return 0;
}
