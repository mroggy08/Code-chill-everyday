#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
int n,a[N][4],dp[N][4],kq;
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= 3; j++){
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= 3; i++) dp[1][i] = a[1][i];
    for (int i = 2; i <= n; i++){
        for (int j = 1; j <= 3; j++){
            if (j==1){
                dp[i][j] = max(dp[i-1][2],dp[i-1][3]) + a[i][j];
            } else if (j==2) {
                dp[i][j] = max(dp[i-1][1],dp[i-1][3]) + a[i][j];
            } else dp[i][j] = max(dp[i-1][1],dp[i-1][2]) + a[i][j];
        }
    }
    kq = max({dp[n][1],dp[n][2],dp[n][3]});
    cout << kq;

    cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";
    return 0;
}
