#include <bits/stdc++.h>
#define ll long long
#define ii pair<ll,int>
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
const int N = 2e5+3;
int n,m,u,v,tr[N],s,t,cnt,kq[N];
vii a[N];
ll d[N],w;
void dij(int s)
{
    priority_queue <ii, vii, greater<ii>> q;
    f1(i,1,n) d[i]=1e18;
    d[s]=0;
//    h1[1] = 0;
    q.push({0,s});
    while (q.size())
    {
        ll du = q.top().fi;
        int u = q.top().se; q.pop();
        if (du > d[u]) continue;
        for (auto e : a[u])
        {
            ll dv = e.fi;
            int v = e.se;
            if (d[v] > du + dv)
            {
                d[v] = du + dv;
//                c[v] = c[u];
////                cout << h1[u] << ' ' << u << '\n';
//                h1[v] = h1[u]+1;
//                h2[v] = max(h2[v],h2[u]+1);
                tr[v]=u;
                q.push({d[v],v});
            }
//            else if (d[v] == du + dv)
//            {
////                cout << h1[u] << ' ';
//                c[v]+=c[u];
//                h1[v] = min(h1[v],h1[u]+1);
//                h2[v] = max(h2[v],h2[u]+1);
//            }
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
    cin >> n >> m >> s >> t;
    while (m--)
    {
        cin >> u >> v >> w;
        a[u].pb({w,v});
        a[v].pb({w,u});
    }
    dij(s);
    cout << d[t] << '\n';
    while (t!=s)
    {
        cnt++;
        kq[cnt] = t;
        t = tr[t];
    }
    kq[++cnt] = s;
    for (int i = cnt; i > 0; i--) cout << kq[i] << ' ';
    return 0;
}

