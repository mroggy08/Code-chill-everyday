#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define Vii vector<ii>
#define X first
#define Y second
#define pri priority_queue <ii,Vii, greater<ii>>
#define pb push_back
#define f1(i,n,m) for (int i=(n);i<=(m);++i)
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;

const int N = 1e2+3;
const int M = 1e5+3;
const int mod = 1e9+7;

int n,W,v[N],w[N]; ll dp[102][100003];
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("INP.INP","r",stdin);
//    freopen("OUT.OUT","w",stdout);
    #endif // ONLINE_JUDGE
    fastIO;
    cin >> n >> W;
    f1(i,1,n) cin >> w[i] >> v[i];
    f1(i,1,n)
        f1(j,1,W)
    {
        dp[i][j] = dp[i-1][j];
        if (j >= w[i]) dp[i][j] = max(dp[i][j],dp[i][j-w[i]] + v[i]);
    }
    cout << dp[n][W];
    return (0^0);
}

