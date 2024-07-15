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
const int N = 1e5+3;
int n,m,u,v,w;
ll d[N];
vii a[N];
void dis()
{
    priority_queue<ii,vii,greater<ii>> q;
    f1(i,1,n) d[i]=1e18;
    d[1]=0;
    q.push({0,1});
    while (q.size())
    {
        ll du = q.top().fi;
        int u = q.top().se;
        q.pop();
        if (du>d[u]) continue;
        for (auto it : a[u])
        {
            ll dv = it.fi;
            int v = it.se;
            if (d[v]>du+dv)
            {
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
        cin >> u >> v >> w;
        a[u].pb({w,v});
    }
    dis();
    f1(i,1,n) cout << d[i] << ' ';
    return 0;
}
