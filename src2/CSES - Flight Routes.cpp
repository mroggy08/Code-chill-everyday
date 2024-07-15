#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,int> ii;
const int N = 1e5+3;
int n,m,k,u,v,cnt[N];
ll w;
vector<ii> a[N];
void dij(){
    priority_queue<ii,vector<ii>,greater<ii>> q;
    q.push({0,1});
    while (q.size()){
        ll du = q.top().fi; int u = q.top().se; q.pop();
        if (cnt[u]>=k) continue;
        if (u==n) cout << du << ' ';
        ++cnt[u];
        for (ii e : a[u]){
            q.push({e.fi+du,e.se});
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
        a[u].pb({w,v});
    }
    dij();
    return 0;
}


