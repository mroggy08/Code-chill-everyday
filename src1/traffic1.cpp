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
int tc,n,m,k,s,t,u,v,w;
vii a[N],g[N];
int d[N],rd[N],kq;
const int inf = 1e9;
void dis(int di)
{
    priority_queue<ii,vii,greater<ii>> q;
    f1(i,1,n) d[i]=inf;
    d[di]=0;
    q.push({0,di});
    while (q.size())
    {
        int du = q.top().fi,u = q.top().se;
        q.pop();
//        if (u==t) {
//            cout << du << '\n';
//            return;
//        }
        if (du > d[u]) continue;
        for (auto it : a[u])
        {
            int dv = it.fi,v = it.se;
            if (d[v] > dv + du)
            {
                d[v] = dv + du;
                q.push({d[v],v});
            }
        }
    }
//    cout << "-1\n";
}
void dis1(int di)
{
    priority_queue<ii,vii,greater<ii>> q;
    f1(i,1,n) rd[i]=inf;
    rd[di]=0;
    q.push({0,di});
    while (q.size())
    {
        int du = q.top().fi,u = q.top().se;
        q.pop();
//        if (u==t) {
//            cout << du << '\n';
//            return;
//        }
        if (du > rd[u]) continue;
        for (auto it : g[u])
        {
            int dv = it.fi,v = it.se;
            if (rd[v] > dv + du)
            {
                rd[v] = dv + du;
                q.push({rd[v],v});
            }
        }
    }
//    cout << "-1\n";
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//    freopen("task.inp","r",stdin);
//    freopen("task.out","w",stdout);
    cin >> tc;
    while (tc--)
    {

        cin >> n >> m >> k >> s >> t;
        f1(i,1,n)
        {
            a[i].clear();
            g[i].clear();
        }
        for (int i = 1; i <= m; i++)
        {
            cin >> u >> v >> w;
            a[u].pb({w,v});
            g[v].pb({w,u});

        }
        dis(s);
        dis1(t);
        kq = d[t];
        f1(i,1,k)
        {
            cin >> u >> v >> w;
            if (d[u]!=1e9 && rd[v]!=1e9)
                kq = min(kq,d[u]+rd[v]+w);
            if (d[v]!=1e9 && rd[u]!=1e9)
                kq = min(kq,d[v]+rd[u]+w);
        }
        if (kq>=1e9) cout << -1 << '\n';
        else cout << kq << '\n';

    }
    return 0;
}
