#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,int> ii;
const int N = 1e5+3;
const int mo = 1e9+7;
const ll inf = 1e18;
int n,m,u,v;
ll w;
vector<ii> a[N];
ll d[N],ma[N],sz[N],mi[N];
void dij(){
    priority_queue<ii,vector<ii>,greater<ii>> q;
    f1(i,2,n) d[i]=inf;
    sz[1]=1;
    q.push({0,1});
    while (q.size()){
        ll du = q.top().fi; int u = q.top().se; q.pop();
        if (du>d[u]) continue;
        for (ii e : a[u]){
            ll dv = e.fi; int v = e.se;
            if (d[v]==du+dv) {
                sz[v] += sz[u];
                sz[v]%=mo;
                mi[v] = min(mi[v],mi[u]+1);
                ma[v]=max(ma[v],ma[u]+1);
            }
            if (d[v]>du+dv){
                d[v]=du+dv;
                q.push({d[v],v});
                sz[v]=sz[u];
                mi[v] = mi[u]+1;
                ma[v]=ma[u]+1;
            }
        }
    }
    cout << d[n] << ' ' << sz[n] << ' ' << mi[n] << ' ' << ma[n];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    cin >> n >> m;
    while (m--){
        cin >> u >> v >> w;
        a[u].pb({w,v});
//        a[v].pb({w,u});
    }
    dij();
    return 0;
}


