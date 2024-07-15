#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define __ThanhDat int main
using namespace std;
const int N = 1e4+3;
const ll mo = 1000000007;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int f[102][102];
ll d[102][102];
int n,m,u,v,w,ha,sa,hb,sb;
vector<int> A,B;
void tv1(int u, int v, int k1, int k2){
    if (f[u][v]==0 && v!=k1 && v!=k2) cout << v << ' ';
    else {
        tv1(u,f[u][v],k1,k2);
        tv1(f[u][v],v,k1,k2);
    }
}
void tv2(int u, int v, int k1, int k2){
    if (f[u][v]==0 && v!=k1 && v!=k2) cout << v << ' ';
    else {
        tv2(u,f[u][v],k1,k2);
        tv2(f[u][v],v,k1,k2);
    }
}
void tv(int u, int v){
    if (!f[u][v]) cout << v << ' ';
    else {
        tv(u,f[u][v]);
        tv(f[u][v],v);
    }
}
__ThanhDat()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    #define task "inp"
    if (fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> m >> ha >> sa >> hb >> sb;
    for (int i = 1; i <= n; i++) for (int j = 1; j<=n; j++) d[i][j] = 1e18;
    while (m--){
        cin >> u >> v >> w;
        d[u][v] = d[v][u] = w;
    }
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                    if (d[i][j]>d[i][k] + d[k][j]){
                        d[i][j] = d[i][k] + d[k][j];
                        f[i][j] = k;
                    }
            }
        }
    }
//    tv1(ha,sa,ha,sa); tv2(hb,sb,hb,sb);
    tv(ha,sa);
    cout << '\n';
    cout << d[ha][sa] << ' ' << d[hb][sb];
    return 0;
}
