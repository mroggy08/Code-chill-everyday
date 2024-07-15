#include <bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define open freopen("TEXT.INP","r",stdin)
using namespace std;
const int N = 1e6;
const int m = 1e9+7;
int main()
{
    fast;
    ll n,d=0;
    cin >> n;
    if (n==0) return cout << 1,0;
    for (int i = 5; i <= n; i*=5)
        d += n/i;
    if (!d) return cout << n%10
//    int ans = (n/d)%10;
//    cout << ans;
    return 0;
}

