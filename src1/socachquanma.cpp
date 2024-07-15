#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k,q,u,v,dp[1003][1003];
char a[1003][1003];
int main()
{
    if(fopen("socach.inp","r")){freopen("socach.inp","r",stdin);freopen("socach.out","w",stdout);}
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> k >> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] = '.';
    a[n][m] = '#';
    while (k--){
        cin >> u >> v;
        a[u][v]='#';
    }
    dp[n][m] = 1;
    for (int i = n; i>0; i--){
        for (int j = m; j>0; j--){
            if (a[i][j]=='.'){
                dp[i][j] = dp[i+2][j-1] + dp[i+2][j+1] + dp[i+1][j+2] + dp[i-1][j+1] + dp[i+1][j-2] + dp[i-1][j-2];
            }
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    while (q--){
        cin >> u >> v;
        cout << dp[u][v] << '\n';
    }

    cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";
    return 0;
}
