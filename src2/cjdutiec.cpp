#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,int> ii;
const int N = 2e5+3;
int n,m,s,t,u,v,kq[N],cnt,tr[N];
ll d[N],w;
vector<ii> a[N];
void dij(int s){
    f1(i,1,n) d[i]=1e18;
    d[s]=0;
    priority_queue<ii,vector<ii>,greater<ii>> q;
    q.push({0,s});
    while (q.size()){
        ll du = q.top().fi; int u = q.top().se;q.pop();
        if (du>d[u]) continue;
        for (ii e : a[u]){
            ll dv=e.fi; int v = e.se;
            if (d[v]>du+dv){
                d[v]=du+dv;
                q.push({d[v],v});
                tr[v]=u;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    cin >> n >> m >> s >> t;
    while (m--){
        cin >> u >> v >> w;
        a[u].pb({w,v});a[v].pb({w,u});
    }
    dij(s);
    cout << d[t] << '\n';
    while (t!=s){
        cnt++;
        kq[cnt]=t;
        t=tr[t];
    }
    kq[++cnt]=s;
    for (int i = cnt; i > 0; i--) cout << kq[i] << ' ';
    return 0;
}


