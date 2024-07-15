#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
#define ll long long
ll n, L, C;
ll a[1001];
ll dp[1001][501];
ll f[1001];

ll cost(ll t) {
    if (t == 0) return 0;
    else if (t <= 10) return -C;
    else return (t - 10) * (t - 10);
}

ll check(ll i, ll t) {
    if (i > n) return 0;
    if (dp[i][t] != -1) return dp[i][t];

    ll ans = INF;
    int t2 = 0;

    for (int j = i; j <= n; ++j) {
        t2 += a[j];
        if (t2 > L) break;

        int t3 = L - t2;
        ll cost2 = cost(t3);

        ll ans2 = check(j + 1, t - t2) + cost2;

        if (ans2 < ans) {
            ans = ans2;
            f[i] = j - i + 1;
        }
    }

    return dp[i][t] = ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("XEPLICH.INP","r",stdin);
    freopen("XEPLICH.OUT","w",stdout);
    cin >> n;
    cin >> L >> C;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    memset(dp, -1, sizeof(dp));

    int minn = check(1, L);

    int i = 1, dem =0;
    while (i <= n) {
        i += f[i];
        dem++;
    }
    cout << dem << "\n";
    cou
