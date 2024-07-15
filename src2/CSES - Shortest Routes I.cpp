#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,int> ii;
const int N = 1e5+5;
int n,m,u,v;
ll d[N],w;
vector<ii> a[N];
void dij(){
    for (int i = 1; i <= n; i++) d[i]=1e18;
    d[1]=0;
    priority_queue<ii,vector<ii>,greater<ii>> q;
    q.push({0,1});
    while (q.size()){
        ll du = q.top().first;
        int u = q.top().se;
        q.pop();
        if (du > d[u]) continue;
        for (ii e : a[u]){
            ll dv = e.first;
            int v = e.second;
            if (d[v]>du+dv){
                d[v]=du+dv;
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
//        a[v].pb({w,u});
    }
    dij();
    for (int i = 1; i <= n; i++) cout << d[i] << ' ';
    return 0;
}

