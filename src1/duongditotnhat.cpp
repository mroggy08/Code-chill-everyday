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
int n,m,u,v,d[N],tr[N];
vi kq;
vii a[N];
void dij()
{
    priority_queue<ii,vii,greater<ii>> q;
    f1(i,1,n) d[i]=1e9;
    d[1]=0;
    q.push({0,1});
    while (q.size())
    {
        int du = q.top().fi, u = q.top().se; q.pop();
        if (d[u]>du) continue;
        for (auto it : a[u])
        {
            int v = it.se, dv = it.fi;
            if (d[v] > du + dv)
            {
                tr[v] = u;
                d[v] = du + dv;
                q.push({d[v],v});
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
        cin >> u >> v;
        a[u].pb({1,v});
        a[v].pb({1,u});
    }
    dij();
    if (d[n]==1e9) cout << "IMPOSSIBLE";
    else {
//        cout << d[n] << '\n';
        while (n!=1)
        {
            kq.pb(n);
            n = tr[n];
        }
        kq.pb(1);
        cout << kq.size() << '\n';
        reverse(kq.begin(),kq.end());
        for (auto it : kq) cout << it << ' ';

    }

    return 0;
}

