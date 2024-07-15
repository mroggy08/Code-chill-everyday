#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pi2 pair<int,pii>
#define vii vector<pii>
#define vi2 vector<pi2>
#define fi first
#define se second
#define pri priority_queue <pi2,vi2, greater<pi2>>
#define pb push_back
#define f1(i, l, r) for (int i = l; i <= r; ++i)
#define f2(i, l, r) for (int i = l; i >= r; --i)
#define f3(i, l, r) for (int i = l; i < r; i++)
#define lb lower_bound
#define ub upper_bound
#define cinarr(a) for (int i = 1; i<=n; ++i) cin >> a[i];
#define cinvec(a) for (auto &x : a) cin >> x;
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define twt int T;cin>>T;while(T--)
 
const int N = 1e6+3;
const int M = 1e3+3;
const int mod = 1e9+7;
const ll inf = 1e12;
 
using namespace std;
pri q;
int dx[]{0,0,1,-1}, dy[]{1,-1,0,0};
int a[M][M],d[M][M],n;
void dis()
{
    d[1][1] = 1;
    q.push({0,{1,1}});
    while (q.size())
    {
        int u = q.top().se.fi;
        int v = q.top().se.se;
        int du =  q.top().fi;
        q.pop();
        if (du > d[u][v]) continue;
        f3(i,0,4) {
            int i2 = u + dx[i];
            int j2 = v + dy[i];
            if (i2>0&&j2>0&&i2<=n&&j2<=n&&d[i2][j2] > max(du,abs(a[i2][j2] - a[u][v])))
            {
                d[i2][j2] = max(du,abs(a[i2][j2]-a[u][v]));
                q.push({d[i2][j2],{i2,j2}});
            }
        }
    }
    cout << d[n][n];
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("INP.INP","r",stdin);
    freopen("OUT.OUT","w",stdout);
    #endif // ONLINE_JUDGE
    faster;
    cin >> n;
    f1(i,1,n) f1(j,1,n) cin >> a[i][j], d[i][j] = 1e9;
    dis();
    return (0^0);
}
 