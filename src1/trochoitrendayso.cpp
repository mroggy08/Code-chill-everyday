#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define __ThanhDat int main
using namespace std;
const int N = 4e2+3;
const ll mo = 1000000007;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int n,m,q,a[N],b[N],x,j,ans;
__ThanhDat()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    #define task "inp"
    if (fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    while (q--)
    {
        cin >> x;
        ans = 1e9;
        for (int i = 1; i <= n; i++)
        {
            j = n;
            while (j > 1 && b[j]>x-a[i]) j--;
            ans = min(ans,abs(a[i]+b[j] - x));
        }
        cout << ans << '\n';
    }
    return 0;
}