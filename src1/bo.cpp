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
const int N = 5e2+3;
ll d[N][N],mn=LLONG_MAX,to;
int n,P,c,g[N],u,v,w,vt;
vii a[N];
void dis(int s, int t)
{
    f1(i,1,P) d[s][i]=1e12;
    priority_queue<ii,vii,greater<ii>> q;
    d[s][s]=0;
    q.push({0,s});
    while(q.size())
    {
//        cout << u << ' ';
        ll du = q.top().fi;
        int u = q.top().se;
        q.pop();
        if (du > d[s][u]) continue;
        for (auto it : a[u])
        {
            ll dv = it.fi;
            int v = it.se;
//            cout << v << '\n';
            if (d[s][v] > du + dv)
            {
                d[s][v] = du+dv;
//                if (v==p) cout << d[v] << '\n';
                q.push({d[s][v],v});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//    freopen("task.inp","r",stdin);
//    freopen("task.out","w",stdout);
    cin >> P >> n >> c;
    f1(i,1,n) cin >> g[i];
    while (c--)
    {
        cin >> u >> v >> w;
        a[u].pb({w,v});
        a[v].pb({w,u});
    }
//    for (auto it : a[4]) cout << it.fi << ' ' << it.se << '\n';
////    dis(1);
////    cout << d[P] << '\n';
    f1(i,1,P)
    {
        to =0;
       f1(j,1,n)
       {
           dis(i,g[j]);
           to+=d[i][g[j]];

       }
//       cout << to << ' ';
       if (mn>to)
           {
               mn = to;
               vt = i;
           }
    }
    cout << vt;
    return 0;
}

