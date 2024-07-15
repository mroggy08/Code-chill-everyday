#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> ii;
const int N = 1e5+9;
vector<ii> g[N];
int h[N],f[N],up[N][17];
void dfs(int u){
    for (ii e : g[u]){
        ll dv = e.first;
        int v = e.second;
        if (v==up[u][0]) continue;

        h[v] = h[u] + 1;
        f[v] = f[u] + dv;

        up[v][0] = u;
        for (int j = 1; j < 10; j++)
            up[v][j] = up[up[v][j-1]][j-1];
        dfs(v);
    }
}
int lca(int u, int v){
    if (h[u]!=h[v]){
        if (h[u]<h[v]) swap(u,v);
        int k = h[u] - h[v];
        for (int j = 0; (1<<j) <= k; j++){
            if (k>>j & 1){
                u = up[u][j];
            }
        }
    }
    if (u==v) return u;
    int k = __lg(h[u]);
    for (int j = k; j>=0; j--){
        if (up[u][j]!=up[v][j]){
            u = up[u][j];
            v = up[v][j];
        }
    }
    return up[u][0];
}
int dist(int u, int v){
    int p = lca(u,v);
    return f[u]+f[v]-2*f[p];
}
void sol(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 1; i < n; i++){
        int u,v;
        ll w;
        cin >> u >> v >> w;
        g[u].push_back({w,v});
        g[v].push_back({w,u});
    }
    dfs(1);
//    string s;
////    while (cin >> s){
////        if (s=="DONE") break;
////        else if (s=="DIST"){
////            int u,v;
////            cin >> u >> v;
////            cout << dist(u,v) << '\n';
////        }
//////        } else {
//////            cout <<
//////        }
////    }
    int u,v;
    cin >> u >> v;
    cout << dist(u,v);
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tc; cin >> tc;
    while (tc--){
        sol();
    }


    cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";
    return 0;
}
