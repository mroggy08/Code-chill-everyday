#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define vi vector<int>
#define vii vector<ii>
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
#define bit(i,x) ((x>>i)&1)
#define bp __builtin_popcount
#define inf INT_MAX
using namespace std;
const int N = 1e3+3;
int n,m,x,u,v,w,g[N][N],d[N],rd[N];
vii a[N];
void dis(int s, int dp[])
{
    priority_queue <ii, vii, greater<ii>> q;
    f1(i,1,n) dp[i]=1e9; dp[s] = 0;
    q.push({0,s});
    while (q.size())
    {
        int du = q.top().fi, u = q.top().se; q.pop();
        if (du > dp[u]) continue;
        for (auto it : a[u])
        {
            int dv = it.fi, v = it.se;
            if (dp[v] > du + dv)
            {
                dp[v] = du + dv;
                q.push({dp[v],v});
            }
        }
    }
    // g[s][x] = dp[x];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define task "task"
    if (fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> m >> x;
    while (m--)
    {
    	cin >> u >> v >> w;
    	a[u].pb({w,v});
    }
    int kq = -1e9;
    f1(i,1,n) {
        dis(i,d);
        dis(x,rd);
        if (d[x]!=1e9 && rd[i] != 1e9)
            {
                kq = max(kq,d[x]+rd[i]);
                // cout << d[x] << ' ' << rd[i] << '\n';
            }
    }
    cout << kq;
   /* dis(1,rd);
    cout << d[]*/
    // f1(i,1,n) cout << g[i][x] << ' ';
    // cout << g[2][2] << ' ';
    return 0;
}
