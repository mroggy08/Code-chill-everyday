#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll e = 1e9;
ll n,m,t;
int a[1005][1005], dp[1005][1005], b[1005][1005];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
void dfs(int i, int j, int p){
    dp[i][j] = p;
    for (int k=0; k<4;k++){
        int i2=i+dx[k];
        int j2=j+dy[k];
        if (i2>=1 && i2<=n && j2>=1 && j2<=m ){
            if (j2 != j ){
                if (dp[i2][j2] > a[i2][j2] + dp[i][j] || dp[i2][j2] == e){
                    dfs(i2,j2, a[i2][j2] + dp[i][j]);
                }
            }
            else
            if (i2 != i ){
                if (dp[i2][j2] > b[i2][j2] + dp[i][j] || dp[i2][j2] == e){
                    dfs(i2,j2,b[i2][j2] + dp[i][j]);
                }
            }
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    freopen("congchua.inp","r",stdin);
//    freopen("congchua.ans","w",stdout);
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++){
            for (int j = 2; j <= m; j++){
                cin >> a[i][j];
                a[i][1] = a[i][2];
                dp[i][j] = e;
            }
        }

        for (int i = 2; i <=n ; i++){
            for (int j = 1; j <= m; j++){
                cin >> b[i][j];
                b[1][j] = b[2][j];
                dp[i][j] = e;
            }
        }
        dp[1][1] = 0;
        dfs(1,1,0);
        cout << dp[n][m] << endl;
    }
    return 0;
}
