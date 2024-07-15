#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+3;
int n,k=2,a[N];
ll dp[N];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    dp[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = 1e9;
        for (int j = max(1,i-k); j < i; j++)
            dp[i] = min(dp[i],dp[j]+ abs(a[i]-a[j]));
    }
    cout << dp[n];
    return 0;
}
