#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,int> ii;
typedef pair<ii,int> i2;
const ll inf = 1e18;
const int N = 1e5+5;
int n,m,w,u,v,k;
ll d[N][19],kq[N];
vector <ii> a[N];
void dijsktra(){
    for (int i = 1; i <= n; i++)
    for (int u = 0; u <= k; u++)
        d[i][u] = inf;
    d[1][0] = 0;
    priority_queue<i2,vector<i2>,greater<i2>> pq;
    pq.push({{0,1},0});
    while (pq.size()){
        ll du = pq.top().fi.fi;
        int u = pq.top().fi.se;
        int fe = pq.top().se;
        pq.pop();
        if (du > d[u][fe]) continue;
        for (ii e : a[u]){
            ll dv = e.first;
            int v = e.second;
            if (d[v][fe] > du + dv) {
                d[v][fe] = du + dv;
                pq.push({{d[v][fe],v},fe});
            }
            if (d[v][fe+1] > d[u][fe] && fe < k){
                d[v][fe+1] = d[u][fe];
                pq.push({{d[v][fe+1],v},fe+1});
            }
        }
    }

}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    while (m--){
        cin >> u >> v >> w;
        a[u].pb({w,v});
        a[v].pb({w,u});
    }
    dijsktra();
//    for (int i = 1; i <= n; i++) cout << d[i][k] << ' ';
    for (int i = 1; i <= n; i++){
        kq[i] = inf;
        for (int j = 0; j <= k; j++){
            kq[i] = min(kq[i],d[i][j]);
        }
    }
        for (int i = 1; i <= n; i++) cout << kq[i] << ' ';
    return 0;
}
