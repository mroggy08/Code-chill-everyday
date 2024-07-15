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

const int N = 1e5+3;
const int inf = 1e9;
const int mo = 1e9+7;
const int dx[4]{1,-1,0,0},dy[4]{0,0,1,-1};
ll kq;
int n,m,k,g[N],u,v,d[N];
vector <ii> a[N];
void dis()
{
    priority_queue<ii,vii,greater<ii>>q;
    f1(i,1,n) d[i]=inf;
    d[1]=0;
    q.push({0,1});
    while (q.size())
    {
        int du = q.top().fi, u = q.top().se;
        q.pop();
        if (du > d[u]) continue;
        for (auto it : a[u])
        {
            int dv = it.fi;
            int v = it.se;
            if (d[v]>du+dv)
            {
                d[v]=du+dv;
                q.push({d[v],v});
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
    cin >> n >> m >> k;
    f1(i,1,k) cin >> g[i];
    while (m--)
    {
        cin >> u >> v;
        a[v].pb({1,u});
    }
    dis();

    f1(i,1,k) kq += d[g[i]];
    cout << kq;
    return 0;
}

