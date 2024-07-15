#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 2e5+5;
int n,u,v,sz[N];
vector<int> a[N];
void dfs(int u, int pre){
    sz[u] = 1;

    for (int v : a[u]){
        if (v==pre) continue;
        dfs(v,u);
        sz[u] += sz[v];
    }
}
int query(int u, int pa){
    for (int v : a[u]){
        if (v!=pa && sz[v]>n/2) return query(v,u);
    }
    return u;
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++){
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
    // xay cay
    dfs(1,0);
//    for (int i = 1; i <= n; i++) cout << sz[i] << ' ';
    cout << query(1,0);
    return 0;
}
