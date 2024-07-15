#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 1e5+3;
const ll inf = 1e18;
int n,m,u,v,w,ok[N],num[N],cnt,low[N],cau;
ll d[N];
vector<ii> a[N];
vector<int> g[N],h[N];
void dij(){
    priority_queue<ii,vector<ii>,greater<ii>>q;
    f1(i,2,n) d[i]=inf;
    q.push({0,1});
    while (q.size()){
        ll du = q.top().fi;
        int u = q.top().se;
        q.pop();
        if (du>d[u]) continue;
        for (ii e : a[u]){
            ll dv = e.fi;
            int v = e.se;
            if (d[v]>du+dv){
                d[v]=du+dv;
                q.push({d[v],v});
                g[v].clear();
                g[v].pb(u);
            } else if (d[v]==du+dv) g[v].pb(u);
        }
    }
}
void dfs(int u){
    for (int v : g[u]){
        h[v].pb(u);
        h[u].pb(v);
        if (!ok[v]){
            ok[v]=1;
            dfs(v);
        }
    }
}
void kc(int u,int pa){
    num[u]=low[u]=++cnt;
    for (int v : h[u]){
        if (v==pa) continue;
        if (num[v]) low[u]=min(low[u],num[v]);
        else {
            kc(v,u);
            low[u]=min(low[u],low[v]);
            if (low[v]==num[v]) cau++;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    cin >> n >> m;
    while (m--){
        cin >> u >> v >> w;
        a[u].pb({w,v});a[v].pb({w,u});
    }
    dij();
    ok[n]=1;
    dfs(n);
    kc(1,0);
    cout << cau;
    return 0;
}

