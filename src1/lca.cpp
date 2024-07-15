#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 2e5+5;
const int lg = 16;
int n,q,u,v,h[N],f[N],up[N][lg+5];
vector<int> a[N];
void dfs(int u){
    for (int v : a[u]){
        if (v==up[u][0]) continue;
        up[v][0] = u;
        h[v] = h[u] + 1;
        f[v] = f[u] + 1;
        for (int j = 1; j < 19; j++)
            up[v][j] = up[up[v][j-1]][j-1];
        dfs(v);
    }

}
void dfs(int u){
    for (int v : a[u]){
        if (v==up[u][0]) continue;
        up[v][0] = u;
        h[v] = h[u] + 1;
        f[v] = f[u] + 1;
        for (int j = 1; j < 19; j++){
            up[v][j] = up[up[v][j-1]][j-1];
        }
        dfs(v);
    }
}
int lca(int u, int v){
    if (h[u]!=h[v]){
        if (h[u]<h[v]) swap(h[u],h[v]);
        int k = h[u] - h[v];
        for (int j = 0; (1<<j) <= k; j++){
            if (k>>j & 1){
                u = up[u][j];
            }
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
int dist(int a, int b){
    return f[a] + f[b] - 2*f[lca(a,b)];
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i < n; i++){
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
    dfs(1);
//    while (q--){
//        cin >> u >> v;
//        cout << dist(u,v) << '\n';
//    }

    return 0;
}
