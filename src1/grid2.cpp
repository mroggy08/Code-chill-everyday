#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
using namespace std;
const int N = 1e3+3, mo = 1e9+7;
int n,m,dp[N][N];
char a[N][N];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//    #ifndef ONLINE_JUDGE
//    freopen("TEXT.INP","r",stdin);
//    #endif
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
//    for (int i = 1; i <= n; i++) dp[i][0] = 0;
//    for (int i = 1; i <= m; i++) dp[0][i] = 0;
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j]=='.')
            {
                if(i > 1) dp[i][j] +=   (dp[i - 1][j])%mo;
                if(j > 1) dp[i][j] +=   (dp[i][j - 1])%mo;
                dp[i][j] %= mo;
            }
            else dp[i][j] = 0;
        }
    cout << dp[n][n];
    return 0;

}
