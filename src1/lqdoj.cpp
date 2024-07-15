#include <bits/stdc++.h>
using namespace std;
int dp[2010][2010];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("INP.INP","r",stdin);
    freopen("OUT.OUT","w",stdout);
    #endif // ONLINE_JUDGE
    string s,kq;
    cin >> s;
    int n = s.length();
    s = '0' + s;
    for (int i = 0; i <= n; i++) dp[1][i] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n - i + 1; j++) {
            if (s[j] == s[j + i - 1])
                dp[i][j] = dp[i - 2][j + 1] + 2,kq+=s[j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + 1]);
        }
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n - i + 1; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << kq;
    // cout << dp[n][1];
}