#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define vi vector<int>
#define vii vector<ii>
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
#define bit(i,x) ((x>>i)&1)
#define bp __builtin_popcount
using namespace std;
const int N = 1e5+3;
int n,u,v,tr[N],f[N],ok,bd,kt,d,kq[N],m;
vi a[N];
void dfs(int s)
{
    f[s]=1;
    for (auto v : a[s])
    {
        if (!f[v])
            {
                tr[v]=s;
                dfs(v);
            }
        else if (f[v] && v!=tr[s])
        {
            ok=1;
            bd = s;
            kt = v;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//    freopen("task.inp","r",stdin);
//    freopen("task.out","w",stdout);
    cin >> n >> m;
    while (m--)
    {
        cin >> u >> v;
        a[u].pb(v);
//        a[v].pb(u);
    }
    f1(i,1,n)
    {
        if(!f[i])
        {
            tr[i]=-1;
            dfs(i);
            if (ok) break;
        }
    }
    if (ok) {
            set<int> se;
//        cout << "YES\n";
//        cout << bd <<  ' ' << kt << '\n';
        while (kt!=bd)
        {
            d++;
            kq[d] = kt;
            kt = tr[kt];
        }
        kq[++d] = bd;
//        kq[0] = bd;
//        cout << d+1 << '\n';
        for (int i = d; i >= 1; i--) se.insert(kq[i]);
        cout << se.size() << '\n';
        for (int it : se) cout << it << ' ';
        return 0;
    }
//    cout << "IMPOSSIBLE";
}
