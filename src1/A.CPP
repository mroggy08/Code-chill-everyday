#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 1e5+5;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("INP.INP","r",stdin);
    freopen("OUT.OUT","w",stdout);
    #endif // ONLINE_JUDGE
    ll a,b;
    cin >> a >> b;
    cout << __gcd(a,b) << '\n';
    cout << a/__gcd(a,b) << ' ' << b/__gcd(a,b);
    return 0;
}