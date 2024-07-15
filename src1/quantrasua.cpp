#include <bits/stdc++.h>
#define vi vector<int>
#define vii vector<ii>
#define ll long long
#define ii pair<ll,int>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)

using namespace std;

const int N = 1e5+3;
const ll inf = 1e18;
const int mo = 1e9+7;
const int dx[4]{1,-1,0,0},dy[4]{0,0,1,-1};
int n,m,u,v,w,k,g[N],h[N];
vector <int> res;
vii a[N];
ll d[N],mx,;
void dis(int s)
{
    f1(i,1,n) d[i] = inf;
    d[s] = 0;
    priority_queue<ii,vii,greater<ii>> q;
    q.push({0,s});
    while (q.size())
    {
        ll du = q.top().fi;
        int u = q.top().se; q.pop();
        if (du > d[u]) continue;
        for (auto it : a[u])
        {
            ll dv = it.fi;
            int v = it.se;
            if (d[v] > du + dv)
            {
                d[v] = du + dv;
                q.push({d[v],v});
            }
        }
    }
    for (int i = 1; i <= n; i++)
        {
            f[s][i] = d[i];
            if (h[s]==1 && g[s] == 0)
            {
                kq[s] = 0;
            }
            else if (h[s]==1&&g[s]==1&&i!=s)
            {
                kq[s] = min(kq[s],f[s][i]);
            }
            else if (h[s]==0)
            {
                kq[s] = min(kq[s],f[s][i]);
            }
        }

}
ll mn(ll a, ll b)
{
    if (a<b) return a;
    return b;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define task "milktea"
    if (fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> m >> k;
    while (m--)
    {
        cin >> u >> v >> w;
        a[u].pb({w,v});
        a[v].pb({w,u});
    }
    while (k--)
    {
        cin >> u >> v;
        h[u] = 1;
        g[u] = v;
        res.pb(u);
    }
    f1(i,1,n) kq[i]=inf;
    f1(i,1,n) dis(i);
    return 0;
}
