#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ii> i2;
const int N = 1e5+3;
const ll inf = 1e18;
vector<ii> a[N];
struct sv{
    ll c,kc;
};
sv d[N];
int n,m,u,v,w;
void dij(){
    priority_queue<i2,vector<i2>,greater<i2>> q;
    f1(i,2,n){
        d[i].c = inf;
        d[i].kc = inf;
    }
    q.push({0,{1,0}});
    while (q.size()){
        ll du = q.top().fi;
        int u = q.top().se.fi;
        int fe = q.top().se.se;
        q.pop();
        if (fe==0){
            if (du>d[u].kc) continue;
        } else {
            if (du>d[u].c) continue;
        }

        for (ii e : a[u]){
            ll dv = e.first;
            int v = e.se;
            if (fe==0){
                if (d[v].kc > du + dv){
                    d[v].kc = du + dv;
                    q.push({d[v].kc,{v,0}});
                }
                if (d[v].c > du + dv/2){
                    d[v].c = du + dv/2;
                    q.push({d[v].c,{v,1}});
                }
            } else {
                if (d[v].c > du + dv){
                    d[v].c = du + dv;
                    q.push({d[v].c,{v,1}});
                }
            }
        }
    }
    cout << d[n].c;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    cin >> n >> m;
    while (m--){
        cin >> u >> v >> w;
        a[u].pb({w,v});
    }
    dij();

    return 0;
}


