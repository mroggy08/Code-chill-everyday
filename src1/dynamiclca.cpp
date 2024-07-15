#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
int n,u,v,q,h[N],pa[N][17];
vector <int> a[N];
void dfs(int u){
    for (int v : a[u]){
        if (v==pa[u][0]) continue;
        h[v] = h[u] + 1;
        pa[v][0] = u;
        for (int i = 1; i < 17; i++){
            pa[v][i] = pa[pa[v][i-1]][i-1];
        }
        dfs(v);
    }
}
int lca(int u, int v){
    if (h[u]!=h[v]){
        if (h[u]<h[v]) swap(u,v);
        int k = h[u] - h[v];
        for (int j = 0; (1<<j)<=k; j++){
            if (k>>j & 1) {
                u = pa[u][j];
            }
        }
    }
    if (u==v) return u;
    int k = __lg(h[u]);
    for (int j = k; j >= 0; j--){
        if (pa[u][j]!=pa[v][j]){
            u = pa[u][j];
            v = pa[v][j];
        }
    }
    return pa[u][0];
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while (cin >> n,n){
        for (int i = 1; i < n; i++) a[i].clear();
        for (int i = 1; i < n; i++){
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        dfs(1);
        char x;
        int root(1);
        cin >> q;
        while (q--){
            cin >> x;
            if (x=='!') cin >> root;
            else {
                cin >> u >> v;
                int Uroot = lca(u,root);
                int Vroot = lca(v,root);
                int UV = lca(u,v);
                cout << (Uroot^Vroot^UV) << '\n';
            }
        }
    }

    cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";
    return 0;
}
