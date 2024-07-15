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
int n,m,u,v,f[N];
vi a[N];
vector <int> kq;
void dfs(int u)
{
    f[u]=1;
    for (auto v : a[u])
    {
        if (!f[v])
        {
            dfs(v);
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
        a[u].pb(v);
        a[v].pb(u);
    }
    f1(i,1,n)
    {
        if (!f[i])
        {
            dfs(i);
            kq.pb(i);
        }
    }
    if (kq.size()<2) cout << 0;
    else {
        cout << kq.size() - 1 << '\n';
        for (int i = 1; i < kq.size(); i++)
        {
            cout << kq[0] << ' ' << kq[i] << '\n';
        }
    }
    return 0;
}

