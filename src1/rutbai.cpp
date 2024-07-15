#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define ii pair<int,int>
using namespace std;
int n,a[102];
ll f[102][102];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    #define task "inp"
    if (fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
//    memset(f,1e12,sizeof f);
//    for (int i = 1; i < n; i++)
//        f[i][i+1] = 0;
//    f[0][0] = 0;
//    for (int i = 1; i <= n; i++){
//        for (int j = n; j >= 1; j--){
//
//            for (int d = i+1; d < j; d++){
//                f[i][j] = min(f[i][j],f[i][d] + f[d][j] + a[i]*a[d]*a[j]);
//            }
//        }
//    }
    for (int u = n; u >= 1; u--){
        for (int v = u+1; v <= n; v++){
//            f[u][v] = 1e12;
            for (int k = u+1; k < v; k++)
                f[u][v] = min(f[u][v],f[u][k] + f[k][v] + a[k]*a[u]*a[v]*1LL);
        }
    }
    cout << f[1][n];
    return 0;
}

