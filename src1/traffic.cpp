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
using namespace std;
const int N = 1e5+3;
int n,m,k,s,t,u,v,w;
vii g[N],rg[N];
int kq,d[N],rd[N];
void inp()
{
    cin >> n >> m >> k >> s >> t;
    f1(i,1,m)
    {
        cin >> u >> v >> w;
        g[u].pb({w,v});
        rg[v].pb({w,u});
    }
}
void dij(int so, vii adj[], int dp[])
{
    priority_queue <ii, vii, greater<ii>> q;
    f1(i,1,n) dp[i] = 1e9;
    dp[so] = 0;
    q.push({0,so});
    while (q.size())
    {
        int u = q.top().se, du = q.top().fi; q.pop();
        if (du > dp[u]) continue;
        for (auto E : adj[u])
        {
            int dv = E.fi, v = E.se;
            if (dp[v] > du + dv) {
                dp[v] = du + dv;
                q.push({dp[v],v});
            }
        }
    }
}
void sol()
{
    dij(s,g,d);
    dij(t,rg,rd);
    kq = d[t];
    f1(i,1,k)
    {
        cin >> u >> v >> w;
        kq = min({kq,d[u]+rd[v]+w,rd[u]+d[v]+w});
    }
    cout << (kq >= 1e9 ? -1 : kq) << '\n';
    f1(i,1,n)
    {
        g[i].clear();
        rg[i].clear();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("task.inp","r",stdin);
    freopen("task.out","w",stdout);
    int T; cin >> T;
    while (T--)
    {
        inp();
        sol();
    }
    return 0;
}
