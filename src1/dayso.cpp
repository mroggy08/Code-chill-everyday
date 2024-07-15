#include <bits/stdc++.h>
#define ll long long
#define X first 
#define Y second
#define ii pair<int,int>
#define f1(i,n,m) for (int i=(n);i<=(m);i++)
using namespace std;
const int N = 1e6+3;
int n,a[N];
ll f[N][2];
ll dp(int id, int t)
{
    if (id>n) return 0;
    if (f[id][t]) return f[id][t];
    ll kq1 = -1e18, kq2 = -1e18;
    kq1 = max(kq1,dp(id+1,!t));
    kq2 = max(kq2,dp(id+1,t));
    if (t) kq1+=a[id];
    else kq1-=a[id];
    return f[id][t]=max(kq1,kq2);
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("TASK.inp","r",stdin);
    freopen("TASK.out","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    f1(i,1,n) cin >> a[i];
    cout << dp(1,1);
    return 0;
}