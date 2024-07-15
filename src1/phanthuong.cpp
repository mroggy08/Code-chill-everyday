#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ii pair<int,int>
#define f first
#define s second
const int N = 1e6+3,M = 1e3+3;
int a[M][M],n,k,i2,j2; ll pre[M][M],ans = -1e18;
int main()
{
    fastIO;
    #ifndef ONLINE_JUDGE
    freopen("TASK.INP","r",stdin);
    #endif // ONLINE_JUDGE
    cin >> n >> k;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
        cin >> a[i][j];
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + a[i][j];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            i2 = i + k - 1; j2 = j + k - 1;
            if (i2>n || j2>n) continue;
            ans = max(ans,pre[i2][j2] - pre[i-1][j2] - pre[i2][j-1] + pre[i-1][j-1]);
        }
    }
    cout << ans;
    return 0;
}
