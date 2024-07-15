#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 2e5+3;
const int lg =18;
int n,q,x,h[N],up[N][lg+2],u,v;
vector<int> a[N];
void dfs(int u){
    for (int v : a[u]){
        if (v==up[u][0]) continue;
        h[v]=h[u]+1;
        up[v][0] = u;
        f1(j,1,lg) up[v][j] = up[up[v][j-1]][j-1];
        dfs(v);
    }
}
int lca(int u, int v){
    if (h[u]!=h[v]){
        if (h[u]<h[v]) swap(u,v);
        int k = h[u] - h[v];
        for (int  j = 0; (1<<j)<=k; j++)
            if (k>>j & 1) u = up[u][j];
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
    f1(i,2,n){
        cin >> x;
        a[x].pb(i);
        a[i].pb(x);
    }
    dfs(1);
    while (q--){
        cin >> u >> v;
        cout << lca(u,v) << '\n';
    }
    return 0;
}


