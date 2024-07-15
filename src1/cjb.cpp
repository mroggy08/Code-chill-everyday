#include <bits/stdc++.h>
#define ll long long
#define f1(i,n,m) for (int i=n; i<=m; i++)
#define pb push_back
using namespace std;

const int N = 1e5+3;

int n,m,u,v,color[N],f[N],ok=1;
vector<int> a[N];
//void dfs(int u, int pr)
//{
//    f[u]=1;
//    g[u] = !g[pr];
//    for (auto v : a[u])
//    {
//        if (!f[v])
//        {
//            dfs(v,u);
//        }
//    }
//}
void bfs(int s)
{
//    f1(i,1,n) color[i] = -1;
    queue<int> q;
    color[s] = 0;
    q.push(s);
    while (q.size())
    {
        int u = q.front();
//        cout << u << ' ';


        q.pop();
        for (int v : a[u])
        {
            if (color[v]==color[u]) {
                ok = 0;
                break;
            }
            if (color[v] == -1)
            {
                color[v] = !color[u];
                q.push(v);
            }
        }
    }
//    cout << '\n';
//    return 1;
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
    f1(i,1,n) color[i] = -1;
    f1(i,1,n) if (color[i]==-1) bfs(i);
    if (!ok) cout << "IMPOSSIBLE";
    else {
        f1(i,1,n) {
            if (color[i]==0) cout << 1 << ' ';
            else cout << 2 << ' ';
        }
    }

    return 0;
}
