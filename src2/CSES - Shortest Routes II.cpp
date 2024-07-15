#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 5e2+5;
int n,u,v,m,q;
ll f[N][N],w;
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) f[i][j] = 1e18;
    for (int i = 1; i <= n; i++) f[i][i]=0;
    while (m--){
        cin >> u >> v >> w;
        f[u][v] = f[v][u] = min(w,f[u][v]);
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
    while (q--){
        cin >> u >> v;
        cout << (f[u][v]!=1e18 ? f[u][v] : -1) << '\n';
    }
    return 0;
}

