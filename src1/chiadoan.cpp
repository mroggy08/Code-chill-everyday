#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define ii pair<int,int>
using namespace std;
int n,k,a[102],tb;
double tam,f[102][102],d[102][102];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    #define task "inp"
    if (fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j++){
            tb = j - i + 1;
            tam = 0;
            for (int k = i; k <= j; k++){
                tam += (double)(a[k]-tb)*(a[k]-tb)/tb;
            }
            f[i][j] = tam;
        }
    }
//    for (int i = 1; i <= n; i++){
//        for (int j = i; j <= n; j++){
//            cout << f[i][j] << ' ';
//        }
//        cout << '\n';
//    }
    for (int i = 1; i <= n; i++) for (int p = 1; p <= k; p++) d[i][p] = (double) 1e14;
    d[0][0] = 0;
    for (int p = 1; p <= k; p++)
    {
        for (int i = p; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                d[i][p] = min(d[i][p],d[j][p-1] + f[j+1][i]);
            }
        }
    }
    cout << d[n][k];
    return 0;
}

