#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3+9;
const int lg = 10;
int tc,n,k,x,h[N],q,u,v;
ll up[N][lg+3];
vector <int> a[1003];
void dfs(int u){
    for (int v : a[u]){
        if (v==up[u][0]) continue;
        h[v] = h[u] + 1;
        up[v][0] = u;
        for (int j = 1; j <= lg; j++)
            up[v][j] = up[up[v][j-1]][j-1];
        dfs(v);
    }
}
//int lca(int u, int v){
//    if (h[u]!=h[v]){
//        if (h[u]<h[v]) swap(u,v);
//        int k = h[u]-h[v];
//        for (int j = 0; (1<<j)<=k; j++)
//           if (k>>j & 1) u = up[u][j];
//    }
//    if (u==v) return u;
//    int k = __lg(h[u]);
//    for (int j = k; j >= 0; j--){
//        if (up[u][j]!=up[v][j]){
//            u = up[u][j];
//            v = up[v][j];
//        }
//    }
//    return up[u][0];
//}
int lca(int u, int v){
    if (h[u]!=h[v]){
        if (h[u]<h[v]) swap(u,v);
        int k = h[u] - h[v];
        for (int j = 0; (1<<j)<=k; j++){
            if (k>>j & 1) {
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
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> tc; for (int it=1;it<=tc;it++){
        cin >> n;
        for (int j = 1; j <= n; j++) a[j].clear();
        for (int j = 1; j <= n; j++){
            cin >> k;
            for (int i = 1; i <= k; i++){
                cin >> x;
                a[x].push_back(j);
                a[j].push_back(x);
            }
        }
//        for (int i = 1; i <= n; i++){
//                cout << i << ' ';
//            for (int v : a[i]){
//                cout << v << ' ';
//            }
//            cout << '\n';
//        }
        dfs(1);
        cout << "Case " << it << ":\n";
//        cout << lca(5,7);
//        cout << h[5] << ' ' << h[7] << '\n';
        cin >> q;
        while (q--){
            cin >> u >> v;
            cout << lca(u,v) << '\n';
        }
    }
    cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";
    return 0;
}
