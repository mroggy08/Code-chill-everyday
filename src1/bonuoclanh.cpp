#include <bits/stdc++.h>
#define ll long long
#define f1(i,n,m) for (int i=n; i<=m; i++)
#define ii pair<int,int>
#define fi first
#define se second
#define vii vector<ii>
#define pb push_back
using namespace std;

const int N = 1e6+3;

int n,m,u,v,w,e;
int d[N];
vii a[N];
void dij()
{
    priority_queue<ii,vii,greater<ii>> q;
    f1(i,1,n) d[i]=1e9;
    d[1] = 1;
    q.push({1,1});
    while (q.size())
    {
        int du = q.top().fi, u = q.top().se; q.pop();
        if (du > d[u]) continue;
        for (auto it : a[u])
        {
            int dv = it.fi, v = it.se;
            if (d[v] > du + dv)
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
        cin >> e >> u >> v;
        a[e].pb({1,v});
        a[e].pb({1,u});
    }
    dij();
    f1(i,1,n) cout << d[i] << '\n';

    return 0;
}

