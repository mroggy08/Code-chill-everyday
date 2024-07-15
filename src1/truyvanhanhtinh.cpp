#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q,u,v,h[200003],up[200003][19];
vector <int> a[200003];
void build(){
    fo
}
int lca(int u, int k){
    for (int j = 0; (1<<j) <= k; j++){
       if (k>>j & 1) u = up[u][j];
    }
    return u;
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i < n; i++){
        cin >> u;
        a[u].push_back(i);
        a[i].push_back(u);
    }
    dfs(1);
    while (q--){
        cin >> u >> v;
        cout<< lca(u,v) << '\n';
    }

    cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";
    return 0;
}
