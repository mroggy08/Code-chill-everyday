#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int n,u,v,f[N],kq;
vector<int> g[N];
void dfs(int u, int pre){
//    cout << u << ' ' << pre << '\n';
    for (int v : g[u]){
        // 2 3
        if (v!=pre){
//            cout << " a " << v << ' ' << u << '\n';
            dfs(v,u);
//            if (u==4) cout << f[u] << ' ' << f[v] << ' ' << u << ' ' << v << '\n';
//            cout << f[u] << ' ' << f[v] << ' ' << u << ' ' << v << '\n';
            kq = max(kq,f[u]+f[v]+1);
            f[u]=max(f[u],f[v]+1);
        }
    }
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,1);
//    for (int i = 1; i <= n; i++) cout << f[i] << ' ';
// dfs(1,1)
// 2 3
// 2,1
// 3,1
// 4 3
// 5 3
// 1 2
    cout << kq;
    cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";
    return 0;
}
