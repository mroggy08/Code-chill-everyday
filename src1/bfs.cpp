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
const int N = 1e5+3;
int n,d[N],v,tr[N],m,s,t,u,dem[N],cnt;
int f[N];
vi a[N];
//void dij(int s)
//{
//    priority_queue<ii,vii,greater<ii>> q;
//    f1(i,1,n) d[i] = 1e9;
//    d[s]=0;
//    q.push({0,s});
//    while (q.size())
//    {
//        int du = q.top().fi, u = q.top().se; q.pop();
//        if (du > d[u]) continue;
//        for (auto it : a[u])
//        {
//            int dv = it.fi, v = it.se;
//            if (d[v] > du + dv)
//            {
//                tr[v] = u;
//                d[v] = du + dv;
//                q.push({d[v],v});
//            }
//        }
//    }
//}
void bfs(int s)
{
    f[s] = 1;
    d[s] = 0;
    queue<int> q;
    q.push(s);
//    cout << s << ' ';
    while (q.size())
    {
        int uu = q.front();
//        cout << uu << ' ';
        q.pop();
        for (auto v : a[uu])
        {
            if (f[v]==1) continue;
            f[v] = 1;
            if (d[v] > d[uu] + 1)
            {
                tr[v] = uu;
                d[v] = d[uu] + 1;

            }
            q.push(v);
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
        cin >> u >> v;
        a[u].pb(v);
    }
    f1(i,1,n) sort(a[i].begin(),a[i].end());
    f1(i,1,n) d[i] = 1e9;
    bfs(s);
    cout << '\n';
//    while (t!=s)
//    {
//        cnt++;
//        dem[cnt] = t;
//        t = tr[t];
//    }
//    cout << f[t] << ' ';
//    cout << t << ' ' << tr[t] << '\n';
//    dem[++cnt] = s;
//    for (int i = cnt; i > 0; i--) cout << dem[i] << ' ';
    f1(i,1,n) cout << f[i] << ' ';
    return 0;
}
