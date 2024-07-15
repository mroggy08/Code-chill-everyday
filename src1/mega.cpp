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

const int N = 1e3+3;
const ll inf = 1e18;
const int mo = 1e9+7;
const int dx[4]{1,-1,0,0},dy[4]{0,0,1,-1};
int n,m,u,v,w;
vii a[N];
ll d[N],h[N][N],kq;
char g[N];
void dis(int s)
{
    priority_queue <ii,vii,greater<ii>> q;
    f1(i,1,n) d[i] = inf;
    q.push({0,s});
    d[s] = 0;
    while (q.size())
    {
        ll du = q.top().fi; int u = q.top().se; q.pop();
        if (du > d[u]) continue;
        for (auto it : a[u])
        {
            ll dv = it.fi;
            int v = it.se;
            if (d[v] > du + dv)
            {
                cout << g[v] << ' ' << g[u] << '\n';
                if (g[v]!=g[u]) {d[v]=d[v]+3+du+dv;}
                else {d[v] = du + dv;}
                q.push({d[v],v});
            }
        }
    }
    for (int i = 1; i <= n; i++) h[s][i] = d[i];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define task "1"
    if (fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> m;
    f1(i,1,n) cin >> g[i];
    while (m--)
    {
        cin >> u >> v;
        a[u].pb({1,v});
        a[v].pb({1,u});
    }
//    f1(i,1,n)
//    {
//        dis(i);
//        f1(j,i+1,n)
//        {
//                cout << i << ' ' << j << ' ' << h[i][j] << '\n';
////                if (g[i] == g[j] && g[i]=='Y') kq += h[i][j], cout << i << ' ' << j << ' ' << h[i][j] << '\n';
//        }
//    }
//    cout << '\n';
//    cout << kq;
    dis(1);
    f1(j,2,n)
        {
                cout << 1 << ' ' << j << ' ' << h[1][j] << '\n';
//                if (g[i] == g[j] && g[i]=='Y') kq += h[i][j], cout << i << ' ' << j << ' ' << h[i][j] << '\n';
        }
    return 0;
}
