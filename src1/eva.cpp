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
int n,m,k,u,v,f[N],g[N];
vi a[N];
queue <int> q;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define task "task"
    if (fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    memset(f,-1,sizeof f);
    cin >> n >> k;
    f1(i,1,k) cin >> g[i],q.push(g[i]),f[g[i]]=0;
    cin >> m;
    while (m--)
    {
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (auto v : a[u])
        {
            if (f[v]==-1)
            {
                f[v] = f[u]+1;
                q.push(v);
            }
        }
    }
    f1(i,1,n) cout << f[i] << ' ';
    return 0;
}

