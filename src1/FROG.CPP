#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pi2 pair<pii,int>
#define vii vector<pii>
#define vi2 vector<pi2>
#define fi first
#define se second
#define pri priority_queue <pii,vii, greater<pii>>
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
 
const int N = 1e5+3;
const int M = 1e3+3;
const int mod = 1e9+7;
const ll inf = 1e12;
 
using namespace std;
int n,a[N],f[N];
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("INP.INP","r",stdin);
    freopen("OUT.OUT","w",stdout);
    #endif // ONLINE_JUDGE
    faster;
    cin >> n; cinarr(a);
    f[1] = a[1];
    f[2] = abs(a[1]-a[2]);
    f1(i,3,n)
        f[i] = min(f[i-2] + abs(a[i-2]-a[i]),f[i-1] + abs(a[i]-a[i-1]));
    cout << f[n];
    return (0^0);
}
 