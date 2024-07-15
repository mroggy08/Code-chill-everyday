#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,s,t,
struct sv{
    int U,V;
};
vector<sv> a[100003];
int tim(int u){
    if (u==pa[u]) return u;
    return pa[u]=find(pa[u]);
}
void tron(int u, int v){
    u = tim(u); v = tim(v);
    if (u!=v){
        if (sz[v]>sz[u]) swap(u,v);
        pa[u] = v;
        sz[v]+=sz[u];
    }
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n  >> s >> t;
    for (int i =1 ;i <= n; i++){
        cin >> u >> v;
        a[i].push_back({u,v});
    }
    for (int i = 1;i <= n; i++) sz[i]=1,pa[i]=i;
    for (int i = 1; i <= n; i++){
        tron(a[i].U, a[i].V)
    }
    cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";
    return 0;
}
