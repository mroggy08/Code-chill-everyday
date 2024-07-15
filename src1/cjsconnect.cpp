#include<bits/stdc++.h>
#define fo(i,n,m) for (int i=n; i<=m; i++)
#define fod(i,n,m) for (int i=n; i>=m; i--)
#define all(a) a.begin(),a.end()
#define fi first
#define se second
#define pf push_front
#define pof pop_front
#define pb push_back
#define pob pop_back
#define eb emplace_back
#define file "task"
#define ii pair<int,int>
#define vii vector<ii>
#define vi vector<int>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=2e5+9;
const int N1=1e3+9;
const ll inf=1e18;
const int Mod= 987654321;
const int dx[]{0,-1,0,1},dy[]{1,0,-1,0};
const double Pi=3.14159265;
int n,m,u,v,f[N];
int tim(int u)
{
    if (u==f[u]) return u;
    return f[u]=tim(f[u]);
}
void tron(int a, int b)
{
    f[b]=a;
}
int32_t main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);
    cin >> n >> m;
    fo(i,1,n) f[i]=i;
    while (m--)
    {
        cin >> u >> v;
        u = tim(u); v = tim(v);
        if (u!=v)
            tron(u,v);
    }
    fo(i,1,n) cout << f[i] << ' ';
    return 0;
}
