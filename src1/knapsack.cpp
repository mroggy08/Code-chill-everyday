#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N,W,w[102],v[102];
ll dp[102][100003];
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> N >> W;
    for (int i = 1; i <= N; i++){
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= W; j++){
            dp[i][j] = dp[i-1][j];
            if (j>=w[i]) dp[i][j] = max(dp[i][j],dp[i-1][j-w[i]] + v[i]);
//            cout <<dp[i][j] << ' ';
        }
//        cout << '\n';
    }
    cout << dp[N][W];
    cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";
    return 0;
}
