#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define vi vector<int>
#define vii vector<ii>
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
const int N=3e5+3;
int n,m,u,v,w;
vii a[N];
ll d1[N],d2[N];
int s1[N],s2[N];
vector<int> kq;
void dis(int s,ll *d,int *c)
{
    priority_queue<ii,vii,greater<ii>> q;
    f1(i,1,n) d[i]=1e12,c[i]=1;
    d[s]=0;
    q.push({0,s});
    while (q.size())
    {
        ll du = q.top().fi;
        int u = q.top().se;
        q.pop();
        if (du>d[u]) continue;
        for (auto i : a[u])
        {
            ll dv = i.fi;
            int v = i.se;
            if (d[v] > du + dv) {
                d[v] = du+dv;
                q.push({d[v],v});
                c[v]=c[u];
            }
            else if (d[v]==du+dv) c[v]+=c[u];
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
    	a[v].pb({w,u});
    }
    dis(1,d1,s1);
    dis(n,d2,s2);
    f1(i,1,n)
    {
        if (!(d1[i]+d2[i]==d1[n] && s1[i]*s2[i]==s1[n])) kq.pb(i);
    }
    cout << kq.size() << '\n';
    for (auto i : kq) cout << i << '\n';

    return 0;
}
