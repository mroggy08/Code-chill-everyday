#include <bits/stdc++.h>
#define ll long long
#define ii pair<ll,ll>
#define fi first
#define se second
#define vi vector<int>
#define vii vector<ii>
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
#define bit(i,x) ((x>>i)&1)
#define bp __builtin_popcount
#define inf INT_MAX
using namespace std;
const int N = 1e6+3;
ii kq[N];
int f[N],u,v,tc;
void sang()
{
    f[0] = f[1] = 1;
    for (int i = 2; i*i <= 1e6; i++)
    {
        if (!f[i])
        {
            for (int j = i*i; j <= 1e6; j+=i)
                f[j] = 1;
        }
    }
    kq[0] = {0,0};
    f1(i,2,1e6)
    {
        if (!f[i])
        {
            kq[i].fi = kq[i-1].fi + i;
            kq[i].se = kq[i-1].se + 1;
        }
        else {
            kq[i].fi = kq[i-1].fi ;
            kq[i].se = kq[i-1].se ;
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
    sang();
    cin >> tc;
    while (tc--)
    {
        cin >> u >> v;
        cout << setprecision(2) << fixed << (double) (kq[v].fi - kq[u-1].fi)/(kq[v].se - kq[u-1].se) << '\n';
    }
    return 0;
}
