#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,int> ii;
const int N = 1e5+3;
int n,m,k,milktea[N],checktea[N],u,v,w,tr[N];
ll d[N],ans[N];
priority_queue<ii,vector<ii>,greater<ii>> q;
vector<ii> a[N];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//    if(fopen("milktea.inp","r")){freopen("milktea.inp","r",stdin);freopen("milktea.out","w",stdout);}
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    cin >> n >> m >> k;
    while (m--){
        cin >> u >> v >> w;
        a[u].pb({w,v});a[v].pb({w,u});
    }
    f1(i,1,k){
        cin >> u >> v;
        milktea[u] = 1;
        checktea[u] = v;
    }
    f1(i,1,n) d[i]=1e18;
    f1(i,1,n) {
        if (milktea[i]){
            q.push({0,i});
            d[i]=0;
        }
    }
    while (q.size()){
        ll du = q.top().fi; int u = q.top().se; q.pop();
        if (du>d[u]) continue;
        for (ii e : a[u]) if (d[e.se] > du + e.fi){
            d[e.se ] = du+e.fi;
            q.push({d[e.se],e.se});
        }
    }
    f1(i,1,n) ans[i] = d[i];
    f1(i,1,n){
        d[i] = 1e18;
        if (milktea[i]){
            q.push({i,0});
            d[i]=0;
            tr[i]=i;
            if (checktea[i]) ans[i]=1e18;
        }
    }
    while (q.size()){
        ll du = q.top().fi; int u = q.top().se; q.pop();
        if (du>d[u]) continue;
        for (ii e : a[u]){
            if (d[e.se] > du + e.fi){
            d[e.se ] = du+e.fi;
            tr[e.se] = tr[u];
            q.push({d[e.se],e.se});
            }
         if (tr[e.se]!=tr[u] && tr[e.se]!=0 && tr[u]!=0){
            ans[tr[e.se]] = min(ans[tr[e.se]], du + d[e.se] + e.fi);
                ans[tr[u]] = min(ans[tr[u]], du + d[e.se] + e.fi);
         }
        }
    }
    f1(i,1,n) cout << ans[i] << ' ';
    return 0;
}


