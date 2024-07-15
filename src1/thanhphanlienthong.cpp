#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first 
#define se second
#define vi vector<int> 
#define vii vector<ii>
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
int n,m,u,v,kq,f[100003];
vector <int> a[100003];
void dfs(int s){
    f[s] = 1;
    for (int v : a[s]){
        if (!f[v]){
            dfs(v);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define task "task"
    if (fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> m;
    while (m--){
        cin >> u >> v;
        a[u].pb(v); a[v].pb(u);
    }
    f1(i,1,n) if (!f[i]) dfs(i),kq++;
    cout << kq;
    

    return 0;
}