#include <bits/stdc++.h>
#define ll long long
#define f1(i,n,m) for (int i=n; i<=m; i++)
#define pb push_back
using namespace std;

const int N = 1e5+3;

int n,m,u,v,g[N],f[N],h[N],ok,tr[N];
vector<int> a[N];
void dfs(int u, int pr)
{
    f[u]=1;
    g[u] = !g[pr];
    for (auto v : a[u])
    {
        if (!f[v])
        {
            dfs(v,u);
        }
    }
}
void dfs1(int u)
{
    h[u] = 1;
    for (auto v : a[u])
    {
        if (!h[v])
        {
            tr[v] = u;
            dfs1(v);
        }
        else if (h[v] && v!=tr[u])
        {
            ok = 1;
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
        if (!h[i])
        {
            dfs1(i);
            if (ok) break;
        }
    }
    if (ok)
    {
        cout << "IMPOSSIBLE";
    } else
    {
        f1(i,1,n)
    {
        if (!f[i])
        {
            dfs(i,0);
        }
    }

    f1(i,1,n)
    {
        if (g[i]) cout << 1 << ' ';
        else cout << 2 << ' ';
    }
    }


    return 0;
}

