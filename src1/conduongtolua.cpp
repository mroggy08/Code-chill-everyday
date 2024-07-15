#include <bits/stdc++.h>
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define vii vector<ii>
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
const int N = 1e5+5;
int n,h[N],m,u,v,d[N],w;
vii a[N];
void dis()
{
        priority_queue <ii, vii, greater<ii>> q;
        f1(i,1,n) d[i]=1e9;
        d[1] = 0;
        q.push({0,1});
        while(q.size())
        {
                int du = q.top().fi, u = q.top().se; q.pop();
                if (du>d[u]) continue;
                for (auto it : a[u])
                {
                        int dv = it.fi, v = it.se;
                        int val = max(du,dv);
                        if (d[v] > val)
                        {
                                d[v] = val;
                                q.push({d[v],v});
                        }
                }
        }
}
int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("task.inp","r",stdin);
//        freopen("task.out","w",stdout);
        cin >> n >> m;
//        f1(i,1,n) cin >> h[i];
        while (m--)
        {
                cin >> u >> v >> w;
                a[u].pb({w,v});
                a[v].pb({w,u});
        }
        dis();
        cout << d[n];
        return 0;
}
