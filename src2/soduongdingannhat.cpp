#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,int> ii;
const int N = 5e3+3;
int n,m,k,u,v,w;
vector<ii> a[N];
ll d[N],sz[N];
void dij(){
    f1(i,2,n) d[i]=1e18;
    sz[1]=1;
    priority_queue<ii,vector<ii>,greater<ii>> q;
    q.push({0,1});
    while (q.size()){
        ll du = q.top().fi; int u = q.top().se; q.pop();
        if (du>d[u]) continue;
        for (ii e : a[u]){
            ll dv = e.fi; int v = e.se;
            if (d[v]>du+dv){
                d[v]=du+dv;
                q.push({d[v],v});
                sz[v]=sz[u];
            } else if (d[v]==du+dv){
                sz[v]+=sz[u];
            }
        }
    }
    cout << d[n] << ' ' << sz[n];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    cin >> n >> m;
    while (m--){
        cin >> k >> u >> v >> w;
        a[u].pb({w,v});
        if (k==2) a[v].pb({w,u});
    }
    dij();
    return 0;
}


