#include <bits/stdc++.h>
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define vii vector<ii>
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
const int N = 1e5+5;
int n,h[N],m,u,v,d[N],s,t,w;
vii a[N];
void dis()
{
        priority_queue <ii, vii, greater<ii>> q;
        f1(i,1,n) d[i]=1e9;
        d[s] = 0;
        q.push({0,s});
        while(q.size())
        {
                int du = q.top().fi, u = q.top().se; q.pop();
                if (du>d[u]) continue;
                for (ii it : a[u])
                {
                        int dv = it.fi, v = it.se,val;
                        if (du!=0) val = min(du,dv);
                        else val = dv;
//                        cout << d[v] << ' ' << val << '\n';
                        if (d[v] < val && d[v]!=1e9)
                        {
                                d[v] = val;
                                q.push({d[v],v});
                        } else if (d[v]==1e9){
                            d[v] = val;
                            q.push({d[v],v});
                        }
                }
        }
}
int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        freopen("taitrong.inp","r",stdin);
        freopen("taitrong.out","w",stdout);
        cin >> n >> m >> s >> t;
        while (m--){
            cin >> u >> v >> w;
            a[u].pb({w,v});
            a[v].pb({w,u});
        }
        dis();
        cout << d[t];
        return 0;
}
