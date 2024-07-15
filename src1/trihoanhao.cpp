#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back

using namespace std;

const int N = 1e5+3;
int n,kq,u,v,dem[N][26],f[N],d[N];
char c;
vector <ii> a[N];

void dfs1(int u, int pre)
{
    for (auto v : a[u])
    {
        if (v.fi == pre) continue;
        dfs1(v.fi,u);
        dem[u][v.se]++;
        d[u] += d[v.fi];
    }
    for (int i = 0; i < 26; i++) d[u] += (dem[u][i] > 1);
}
void dfs2(int u, int pre)
{
    for (auto v : a[u])
    {
        if (v.fi==pre) continue;
        dem[v.fi][v.se]++;
        int ans1 =0,ans2 = 0;
        if (dem[u][v.se]==2) ans1 = 1;
        if (dem[v.fi][v.se]==2) ans2 = 1;
        f[v.fi] = f[u] + d[u] - d[v.fi] - ans1 + ans2;
        dfs2(v.fi,u);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("trie.inp","r",stdin);
    freopen("trie.out","w",stdout);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v >> c;
        a[u].pb({v,c-'a'});
        a[v].pb({u,c-'a'});
    }
    dfs1(1,0);
    dfs2(1,0);
    for (int i = 1; i <= n; i++)
        if (!(d[i]+f[i])) kq++;
        cout << kq;
    return 0;
}
