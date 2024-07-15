#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define __ThanhDat int main
using namespace std;
const int N = 1e4+3;
const ll mo = 1000000007;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

ll n,m,r,q,a[N],kq;
__ThanhDat()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    #define task "inp"
    if (fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1,a+n+1);
    for (int i = 1; i < n-1; i++)
    {
        q = m - a[i];
        r = n;
        for (int j = i+1; j < n; j++)
        {
            while (r>j && a[j]+a[r]>q) r--;
            if (r>j) kq += r-j;
        }
    }
    cout << kq;
    return 0;
}
