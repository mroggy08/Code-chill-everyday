#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 1e5+3;
int m,n,k,x,f[N],u,v;
vector<int> a[N];
queue<int> q;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    cin >> n >> k;
    f1(i,1,n) f[i]=-1;
    f1(i,1,k) {
        cin >> x;
        f[x]=0;
        q.push(x);
    }
    cin >> m;
    while (m--){
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
    while (q.size()){
        int u = q.front();
        q.pop();
        for (int v : a[u]){
            if (f[v]==-1){
                f[v]=f[u]+1;
                q.push(v);
            }
        }
    }
    f1(i,1,n) cout << f[i] << ' ';
    return 0;
}


