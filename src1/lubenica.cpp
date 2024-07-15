#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define bit(x, k) (1ll&((x) >> (k)))
const int INF = 1e9;
struct sv{
    int pa,minc=INF,maxc=-INF;
};
const int N = 1e5+5;
int n,u,v,w,h[N],q;
sv up[N][21];
vector <ii> a[N];
void dfs(int u){
    for (ii e : a[u]){
        int dv = e.first, v = e.second;
        if (v==up[u][0].pa) continue;
        up[v][0].pa = u;
        up[v][0].maxc = up[v][0].minc = dv;
        h[v] = h[u] + 1;
        for (int j = 1; j < 21; j++){
            up[v][j].pa = up[up[v][j-1].pa][j-1].pa;
            up[v][j].maxc = max(up[v][j-1].maxc,up[up[v][j-1].pa][j-1].maxc);
            up[v][j].minc = min(up[v][j-1].minc,up[up[v][j-1].pa][j-1].minc);
        }
        dfs(v);
    }
}
sv lca(int u, int v){
    sv kq;
    if (h[u]!=h[v]){
        if (h[u]<h[v]) swap(u,v);
    int k = h[u] - h[v];
        for (int j = 0; (1<<j)<=k; j++){
            if (bit(k, j)){

                kq.maxc = max(kq.maxc,up[u][j].maxc);
                kq.minc = min(kq.minc,up[u][j].minc);
                 u = up[u][j].pa;
            }
        }
    }
    if (u==v) {
        return kq;
    }
    int k = __lg(h[u]);
    for (int j = k; j >= 0; j--){
        if (up[u][j].pa!=up[v][j].pa){
            kq.maxc = max({kq.maxc,up[u][j].maxc,up[v][j].maxc});
            kq.minc = min({kq.minc,up[u][j].minc,up[v][j].minc});
             u = up[u][j].pa;
            v = up[v][j].pa;
        }
    }
    kq.maxc = max({kq.maxc, up[u][0].maxc, up[v][0].maxc});
    kq.minc = min({kq.minc, up[u][0].minc, up[v][0].minc});
    return kq;
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++){
        cin >> u >> v >> w;
        a[u].push_back({w,v});
        a[v].push_back({w,u});
    }
    dfs(1);
    cin >> q;
    while (q--){
        cin >> u >> v;
        cout << lca(u,v).minc << ' ' << lca(u,v).maxc << '\n';
    }
    cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";
    return 0;
}
