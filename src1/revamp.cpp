#include <bits/stdc++.h>
#define ll long long
#define ii pair<ll,int>
#define i3 pair<int,int>
#define i2 pair<ii,int>
#define fi first
#define se second
#define vi2 vector<i2>
#define f1(i,n,m) for (int i=n; i<=m; i++)
#define pb push_back
using namespace std;
const int N = 1e5+3;
const ll inf = 1e18;
int n,m,k=1,u,v,w;
vector<ii> a[N];
ll d[N][23];
ll mn(ll a, ll b)
{
    if (a<b) return a;
    return b;
}
void dis()
{
    priority_queue<i2,vi2,greater<i2>> q;
    d[1][0] = 0;
    q.push({{0,1},0});
    while (q.size())
    {
        ll du = q.top().fi.fi; int u = q.top().fi.se, fe = q.top().se;
        q.pop();
        if (du > d[u][fe]) continue;
        for (auto it : a[u])
        {
            if (d[it.se][fe] > du+it.fi)
            {
                d[it.se][fe] = du+it.fi;
                q.push({{d[it.se][fe],it.se},fe});
            }
            if (d[it.se][fe+1]>du&& fe<k)
            {
                d[it.se][fe+1] = du;
                q.push({{d[it.se][fe+1],it.se},fe+1});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define task "task"
    if (fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> m;
    while (m--)
    {
        cin >> u >> v >> w;
        a[u].pb({w,v});
        a[v].pb({w,u});
    }

    f1(i,1,n) f1(j,0,k) d[i][j] = inf;
    dis();
    ll mx = LLONG_MAX;
    for (int i = 0; i <= k; i++) mx = mn(mx,d[n][i]);
    cout << mx;
    return 0;
}
