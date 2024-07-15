#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 1e6+3;
int n,h[N];
ll dp[N];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    cin >> n;
    f1(i,1,n) cin >> h[i];
    // dp[1] = 0;
    dp[2] = abs(h[1] - h[2]);
    f1(i,3,n) dp[i] = min(dp[i-1] + abs(h[i-1]-h[i]), dp[i-2] + abs(h[i-2]-h[i]));
    cout << dp[n];
    return 0;
}
