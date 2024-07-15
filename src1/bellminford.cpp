#include<bits/stdc++.h>
#define fo(i,n,m) for (int i=n; i<=m; i++)
#define fod(i,n,m) for (int i=n; i>=m; i--)
#define all(a) a.begin(),a.end()
#define fi first
#define se second
#define pf push_front
#define pof pop_front
#define pb push_back
#define pob pop_back
#define eb emplace_back
#define file "task"
#define ii pair<int,int>
#define vii vector<ii>
#define vi vector<int>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=2e5+9;
const int N1=1e3+9;
const ll inf=1e18;
const int Mod= 987654321;
const int dx[]{0,-1,0,1},dy[]{1,0,-1,0};
const double Pi=3.14159265;
int n,m,u,v;
ll w;
vector<ll> d;
struct sv
{
    int u,v;
    ll w;
};
vector<sv> e;
void bellmanford()
{
    d.resize(n,inf);
    d[1] = 0;
    for (int T = 1; T < n; T++)
    {
        for (auto g : e)
        {
            int u = g.u;
            int v = g.v;
            ll w = g.w;
            if (d[u]!=inf && d[v]>d[u]+w)
            {
                d[v] = d[u]+w;
            }
        }
    }
}
int32_t main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);
    cin >> n >> m;
    while (m--)
    {
        cin >> u >> v >> w;
        e.pb({u,v,w});
    }
    bellmanford();
    cout << d[n];
    return 0;
}

