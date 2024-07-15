#include <bits/stdc++.h>
#define f1(i,n,m) for (int i=n; i<=m; i++)
#define file(name)  if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }
#define ll long long
#define fi first
#define se second
#define ii pair<int,int>
using namespace std;
const int N = 2222;
const int oo = 1e9+7;
void Dij(){
    priority_queue <ii, vector<ii>, greater<ii>> q;
    q.push({0,1});
    f1(i,2,n) d[i] = oo;
    while (q.size()){
        int du = q.top().fi, u = q.top().se; q.pop();
        if (du>d[u]) continue;
        for (ii e : a[u]){
            int dv = e.fi, v = e.se;
            if ()
        }
    }    
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    file("1");
    cin >> n >> m >> q;
    while (m--){
        int u,v,w;
        cin >> u >> v >> w;
        a[u].push_back({w,v});a[v].push_back({w,u});
    }
    Dij();
    while (q--){
        int S,T;
        cin >> S >> T;
        cout << d[S] - ma[S] + T << '\n'; 
    }
    return 0;
}



