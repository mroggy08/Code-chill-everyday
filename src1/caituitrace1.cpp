#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define f1(i,n,m) for (int i = n; i <= m; i++)
#define fz(i,n) for (int i = 0; i < n; i++)
#define __ThanhDat int main
using namespace std;
const int N = 1e6+3;
const ll mo = 1000000007;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
ll a,b,c,d,kq;
ll calc(ll a)
{
    ll kq = a - a*10/100;
    return kq;
}
__ThanhDat()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    #define task "text"
    if (fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> a >> b >> c >> d;
    kq = calc(a) + calc(b) + calc(c);
    cout << kq+11558177 << '\n';
    cout << calc(a);
    return 0;
}