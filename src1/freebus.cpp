#include <bits/stdc++.h>
#define ll long long
#define ii pair<ll,int>
#define fi first
#define se second
#define vi vector<int>
#define vii vector<ii>
#define i2 pair<ii,int>
#define vi2 vector<i2>
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
#define bit(i,x) ((x>>i)&1)
#define bp __builtin_popcount
#define inf INT_MAX
using namespace std;
const int N = 1e5+3;
ll d[N][3],mx=INT_MAX;
int n,m,u,v,w;
vii a[N];
ll mn(ll a, ll b)
{
    if (a<b) return a;
    return b;
}
void dis()
{
    f1(i,1,n)  f1(j,0,1) d[i][j] = 1e18;
    d[1][1] = 0;
    priority_queue<i2,vi2,greater<i2>> q;
    q.push({{0,1},0});
    while (q.size())
    {
        ll du = q.top().fi.fi;
        int u = q.top().fi.se, fe = q.top().se;
        q.pop();
        if (du > d[u][fe]) continue;
        for (auto it : a[u])
        {
            if (d[it.se][fe] > du + it.fi)
            {
                d[it.se][fe] = du + it.fi;
                q.push({{d[it.se][fe],it.se},fe});
            }
            if (d[it.se][fe+1] > d[u][fe] && fe<1)
            {
                d[it.se][fe+1] = d[u][fe];
                q.push({{d[it.se][fe+1],it.se},fe+1});
            }
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
        cin >> u >> v >> w;
        a[u].pb({w,v});
    }
    dis();
    f1(i,0,1) mx=mn(mx,d[n][i]);
    cout << mx;
    return 0;
}

