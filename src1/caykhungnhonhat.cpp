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

const int N = 1e6+3;
const ll inf = 1e18;
const int mo = 1e9+7;
const int dx[4]{1,-1,0,0},dy[4]{0,0,1,-1};
ll n,m,u,v,w,kq,f[N],h[N],tp;
vi a[N];
struct sv
{
    ll a,b,c;
};
vector <sv> ed;
bool cmd(sv a, sv b)
{
    return a.c < b.c;
}
ll tim(ll u)
{
    if (u==f[u]) return u;
    return f[u] = tim(f[u]);
}
bool tron(ll a, ll b)
{
    a = tim(a);b=tim(b);
    if (a==b) return 0;
    f[b] = a;
    return 1;
}
void dfs(int s)
{
    h[s] = 1;
    for (int v : a[s])
    {
        if (!h[v]) dfs(v);
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
        cin >> u >> v >> w;
        a[u].pb(v);
        a[v].pb(u);
        ed.pb({u,v,w});
    }
    f1(i,1,n) if (!h[i]) dfs(i),tp++;
    if (tp>1) cout << "IMPOSSIBLE"; else {
    sort(ed.begin(),ed.end(),cmd);
    f1(i,1,n) f[i]=i;
    for (auto it : ed)
        {
            if (tron(it.a,it.b))
            {
                kq+=it.c;
            }
        }
        cout << kq;
    }
    return 0;
}

