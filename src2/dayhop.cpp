#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 1e5+3;
int n,m,k,g[N],u,v,d[N];
vector<ii> a[N];
ll kq;
void dij(){
    priority_queue<ii,vector<ii>,greater<ii>>q;
    f1(i,2,n) d[i]=1e9;
    q.push({0,1});
    while (q.size()){
        int du = q.top().fi,u=q.top().se; q.pop();
        if (du>d[u]) continue;
        for (ii e : a[u]){
            if (d[e.se] > du + e.fi){
                d[e.se] = du+e.fi;
                q.push({d[e.se],e.se});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
//    cin >> n >> m >> k;
//    f1(i,1,k) cin >> g[i];
//    while (m--){
//        cin >> u >> v;
//        a[u].pb({1,v});
//    }
//    dij();
////    cout << d[n] << '\n';
//    f1(i,1,k) kq+=d[g[i]];
//    cout << kq;
//    return 0
     cin >> n >> m >> k;
    f1(i,1,k) cin >> g[i];
    while (m--)
    {
        cin >> u >> v;
        a[v].pb({1,u});
    }
    dij();

    f1(i,1,k) kq += d[g[i]];
    cout << kq;
    return 0;
}


