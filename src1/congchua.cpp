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
const int N = 1e6+3;
int tc,n,m,k,x,w,u,v;
ll d[1000003];
vii g[N];
void dis()
{
    f1(i,1,n*m) d[i] = 1e18;
    priority_queue <ii, vii, greater<ii>> q;
    d[1] = 0;
    q.push({0,1});
    while (q.size())
    {
        ll du = q.top().fi;
        int u = q.top().se;
        q.pop();
        if (du > d[u]) continue;
        for (auto it : g[u])
        {
            ll dv = it.fi;
            int v = it.se;
            if (d[v] > du + dv)
            {
                d[v] = du + dv;
                q.push({d[v],v});
//                if (v==(n*m)) return;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("congchua.inp","r",stdin);
    freopen("congchua.out","w",stdout);
    cin >> tc;
    while(tc--)
    {
        cin >> n >> m;
        f1(i,1,n)
        {
            k = (i-1)*m;
//            cout << k << '\n';
            f1(j,1,m-1)
            {
                cin >> x;
//                cout << k+j << ' ' << k+j+1 << '\n';
                g[k+j].pb({x,k+j+1});
                g[k+j+1].pb({x,k+j});

            }
        }
        f1(i,1,n-1)
        {
            k = (i-1)*m;
            f1(j,1,m)
            {
                cin >> x;
//                cout << k+j << ' ' << k+j+m << '\n';
                g[k+j].pb({x,k+j+m});
                g[k+j+m].pb({x,k+j});
            }
        }
//        for (int i = 1; i <= n; i++)
//                        for (int j = 1; j < m; j++)
//                        {
//                                cin >> w;
//                                u = m * (i - 1) + j;
//                                v = u + 1;
//                                g[u].push_back({w, v});
//                                g[v].push_back({w, u});
//                        }
//                for (int i = 1; i < n; i++)
//                {
//                        for (int j = 1; j <= m; j++)
//                        {
//                                cin >> w;
//                                u = m * (i - 1) + j;
//                                v = u + m;
//                                g[u].push_back({w, v});
//                                g[v].push_back({w, u});
//                        }
//                }
        dis();
        cout << d[n*m] << '\n';
       f1(i,1,n*m) g[i].clear();
//        g.clear();
    }
    return 0;
}

