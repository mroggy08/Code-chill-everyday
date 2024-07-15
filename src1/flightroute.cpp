#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,sse4,avx,avx2,fma,bmi,bmi2,abm")
#include<bits/stdc++.h>
#define TrThanhDat int main()
#define ii pair<int,int>
#define fi first
#define se second
#define f1(i,n,m) for(int i=n;i<=m;i++)
#define f2(i,n,m,j) for (int i=n;i>=m;i-=j)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lb;
void fan_manchesterunited_20nam() {ios_base::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);}
void times() {cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";}
ll gcd(ll a, ll b) {return __gcd(a,b);}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}
const ll mod = 1e9+7;
const int N = 2e5+3;
int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
char duong[] = {'R', 'L', 'D', 'U'};
const ll inf = 1e18;
vector<vector<pair<ll,ll>>> a;
vector<vector<ll>> d;
ll n,m,u,v,w,k;
void dis()
{
    priority_queue<ii,vector<ii>,greater<ii>> q;
//    f1(i,2,n) d[i] = inf;
//    d[1] = 0;
    q.push({0,1});
    while (q.size())
    {
        ll du = q.top().first;
        int u = q.top().se;
        q.pop();
        if (du > d[u][k-1]) continue;
        for (auto e : a[u])
        {
            ll dv = e.fi;
            int v = e.se;
            if (d[v][k-1] > du + dv)
            {
                d[v][k-1] = du + dv;
                q.push({d[v][k-1],v});
                sort(d[v].begin(),d[v].end());
            }
        }
    }
}
TrThanhDat {
    fan_manchesterunited_20nam;
    #define name "task"
    if(fopen(name".inp","r")){freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
    cin >> n >> m >> k;
    a.resize(n+1);
    d.resize(n+1);
    for (int i = 1; i <= n; i++)
    {
        d[i].resize(k);
        for (int j = 0; j < k; j++)
            d[i][j] = inf;
    }
    d[1][0] = 0;
    while (m--)
    {
        cin >> u >> v >> w;
        a[u].push_back({w,v});
    }
    dis();
    for (int i = 0; i < k; i++)
        cout << d[n][i] << ' ';
    times();
    return (0 ^ 0);
}
