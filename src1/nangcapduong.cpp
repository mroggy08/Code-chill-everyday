#include <bits/stdc++.h>
#define vi vector<int>
#define vii vector<ii>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)

using namespace std;

const int N = 2e5+3;
const ll inf = 1e18;
const int mo = 1e9+7;
const int dx[4]{1,-1,0,0},dy[4]{0,0,1,-1};
int n,m,u,v,w,f[N],tr[N],num[N],low[N],id,cau;
ll d[N];
vector <ii> a[N];
vi g[N],h[N];
void dis()
{
    priority_queue<ii,vii,greater<ii>>q;
    f1(i,1,n) d[i] = inf;
    d[1] = 0;
    q.push({0,1});
    while (q.size())
    {
        ll du = q.top().fi;
        int u = q.top().se;
        q.pop();
        if (du > d[u]) continue;
        for (auto it : a[u])
        {
            ll dv = it.fi;
            int v = it.se;
            if (d[v] > du + dv)
            {
                g[v].clear();
                d[v] = du + dv;
                q.push({d[v],v});
                g[v].pb(u);
            } else if (d[v] == du + dv) g[v].pb(u);
        }
    }
}
void dfs(int s)
{
   for (auto it : g[s])
   {
//       cout << s << ' ' << it << '\n';
       h[s].pb(it);
       h[it].pb(s);
       if (!f[it])
       {
           f[it]=1;
           dfs(it);
       }
   }
}
void df(int u, int pre)
{
    num[u] = low[u] = ++id;
    for (auto it : h[u])
    {
        if (it==pre) continue;
        if (num[it]) low[u] = min(low[u],num[it]);
        else {
            df(it,u);
            low[u] = min(low[u],low[it]);
            if (low[it]==num[it]) cau++;
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
    dis();
    f[n]=1;
    dfs(n);
    df(1,0);
    cout << cau;
//    f1(i,1,n)
//    {
//        cout << i << ' ';
//        for (auto it : g[i])
//            cout << it << ' ';
//        cout<<'\n';
//    }
    return 0;
}
