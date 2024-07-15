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
const int N = 2e5+5;
const int lg = 18;
int n,k,h[N],up[N][lg+2],root;
VI group[N],ke[N];
void dfs(int u){
    for (int v : ke[u]){
        h[v] = h[u] + 1;
        for (int j = 1; j < lg; j++) up[v][j] = up[up[v][j-1]][j-1];
        dfs(v);
    }
}
int lca(int u, int v){
    if (h[u]!=h[v]){
        if (h[u]<h[v]) swap(u,v);
        int k = h[u] - h[v];
        for (int j = 0; (1<<j) <= h[u]-h[v]; j++) if (k>>j&1) u=up[u][j];
    }
    if (u==v) return u;
    int k = __lg(h[u]);
    for (int j= k; j >= 0; j--){
        if (up[u][j]!=up[v][j]){
            u = up[u][j];
            v = up[v][j];
        }
    }
}
int kc(int u, int v){
    return h[u]+h[v]-2*h[lca(u,v)];
}
int sol(vector<int> &A){
    int bd = A[0], B = bd, maximum = 0,len;
    for (int v : A){
        len = kc(v,bd);
//        cout << len << ' ';
        if (len>maximum){
            maximum = len;
            B = v;
        }
    }
//    cout << B << ' ';
    maximum = 0;
    for (int v : A) maximum = max(maximum,kc(B,v));
    return maximum;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    f1(i,1,n){
        int x;
        cin >> x >> up[i][0];
        group[x].pb(i);
        ke[up[i][0]].pb(i);
        if (!up[i][0]) root=i;
    }
    dfs(root);
    f1(j,1,k){
        cout << sol(group[j]) << '\n';
    }
    return 0;
}
