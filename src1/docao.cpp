#include <bits/stdc++.h>
#define vi vector<int>
#define vii vector<ii>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)

using namespace std;

const int N = 1e6+3;
const ll inf = 1e18;
const int mo = 1e9+7;
const int dx[4]{1,-1,0,0},dy[4]{0,0,1,-1};
int n,m,u,v,w,h[403],k;
ll s,mn,f[403][403];
ll mnn(ll a, ll b)
{
    if (a<b) return a;
    return b;
}
ll mx(ll a, ll b)
{
    if (a>b) return a;
    return b;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define task "task"
    if (fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> k;
    f1(i,1,n) cin >> h[i];
    f1(i,1,n) f1(j,0,k) f[i][j] = inf;
    f[1][0] = 0;
    for (int i = 2; i <= n; i++)
    {
        s = 0; mn = 0;
        for (int j = i; j > 0; j--)
        {
            s+=h[j];
            mn = mx(mn,h[j]);
        }
        f[i][0] = mn * i - s;
    }
    f1(i,1,n) cout << f[i][0] << ' ';
    f1(i,2,n)
    {
        f1(d,1,k)
        {
            s = 0; mn = 0;
            for (int j = i; j > 1; j--)
            {
                s+=h[j];
                mn = mx(mn,h[j]);
                f[i][d] = mnn(f[i][d],f[i-1][d-1] + mn*(i-j+1) - s);
            }

        }
    }
    cout << f[n][k];

    return 0;
}

