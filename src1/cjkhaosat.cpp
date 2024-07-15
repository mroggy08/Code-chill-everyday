#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4e2+9;
int n,m,q,u,v,w;
ll f[N][N];
ll MIN(ll a, ll b){
    if (a<b) return a;
    return b;
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++) f[i][j] = 1e12;
    }
    for (int i = 1; i <= n; i++) f[i][i] = 0;
    while (m--){
        cin >> u >> v >> w;
        f[u][v] = f[v][u] = MIN(f[u][v],w);
    }
//    cout << f[1][5] << ' ';
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
//                cout << f[i][j] << ' ' << f[i][k] + f[k][j] << '\n';
                f[i][j] = MIN(f[i][j],f[i][k] + f[k][j]);
            }
        }
    }
//    cout << f[1][5] << '\n';
    while (q--){
        cin >> u >> v;
        cout << f[u][v] << '\n';
    }

    cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";
    return 0;
}
