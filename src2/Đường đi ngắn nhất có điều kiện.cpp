#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,int> ii;
typedef pair<ii,int> i2;
const int N = 1e5+3;
const ll inf = 1e18;
int n,m,w,u,v,k;
ll d[N][19],kq[N];
vector <ii> a[N];
void dij(){
    f1(i,1,n) f1(j,0,k) d[i][j]=inf;
    d[1][0]=0;
    priority_queue<i2,vector<i2>,greater<i2>>q;
    q.push({{0,1},0});
    while (q.size()){
        ll du = q.top().fi.fi; int u = q.top().fi.se, fe = q.top().se; q.pop();
        if (du>d[u][fe]) continue;
        for (ii e : a[u]){
            ll dv = e.fi; int v = e.se;
            if (d[v][fe]>du+dv){
                d[v][fe]=du+dv;
                q.push({{d[v][fe],v},fe});
            }
            if (d[v][fe+1]>d[u][fe] && fe < k){
                d[v][fe+1] = d[u][fe];
                q.push({{d[v][fe+1],v},fe+1});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    cin >> n >> m >> k;
    while (m--){
        cin >> u >> v >> w;
        a[u].pb({w,v});a[v].pb({w,u});
    }
    dij();
    f1(i,1,n){
        kq[i]=inf;
        f1(j,0,k) kq[i]=min(kq[i],d[i][j]);
    }
    f1(i,1,n) cout << kq[i] << ' ';
    return 0;
}

