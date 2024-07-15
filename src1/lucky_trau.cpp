#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N = 1e6+5;
const ll inf = 1e18;
const int mo = 1e9+7;
int n,l,r;
ll a[N],m,kq,k;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    freopen("task.inp","r",stdin);
    freopen("task.OUT","w",stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1,a+n+1);
    for (int i = 1; i <= n; i++)
    {
        m = k - a[i];
        l = lower_bound(a+i+1,a+n+1,m) - a;
        r = upper_bound(a+i+1,a+n+1,m) - a;
        if (a[l]==m) kq+=(r-l);
    }
    for (int i = 1; i <= n; i++)
    {
        m = -k - a[i];
        l = lower_bound(a+1+i,a+n+1,m) - a;
        r = upper_bound(a+1+i,a+n+1,m) - a;
        if (a[l]==m) kq+=(r-l);
    }
    cout << kq;
    return 0;
}

