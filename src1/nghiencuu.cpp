#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,int> ii;
const int N = 1e5+5;
const ll inf = 1e18;
const int mo = 1e9+7;
int n,m;
int u,v;
ll w,d[N],sz[N];
vector <ii> a[N];
struct sv {
    ll ma,mi;
};
sv kq[N];
void dij(){
    priority_queue<ii,vector<ii>,greater<ii>> q;
    sz[1] = 1;
    q.push({0,1});
    while (q.size()){
        ll du = q.top().fi;
        int u = q.top().se;
        q.pop();
        if (du > d[u]) continue;
        for (ii e : a[u]){
            ll dv = e.first;
            int v = e.second;
            if (d[v] == du + dv){
                sz[v] += sz[u];
                sz[v] %= mo;
                kq[v].ma = max(kq[v].ma,kq[u].ma+1);
                kq[v].mi = min(kq[v].mi,kq[u].mi+1);
            }
            if (d[v] > du + dv){
                sz[v] = sz[u];
                kq[v].ma = kq[u].ma + 1;
                kq[v].mi = kq[u].mi + 1;
                d[v] = du + dv;
                q.push({d[v],v});
            }
        }
    }
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    while (m--){
        cin >> u >> v >> w;
        a[u].pb({w,v});
    }
    for (int i = 2; i <= n; i++)
        d[i] = inf;
    dij();
    cout << d[n] << ' ' << sz[n] << ' ' << kq[n].mi << ' ' << kq[n].ma;
    return 0;
}
