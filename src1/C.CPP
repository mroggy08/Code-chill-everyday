#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pri priority_queue <pii,vii, greater<pii>>
#define pb push_back
#define f1(i, l, r) for (int i = l; i <= r; ++i)
#define fd(i,n) for (int i = 0; i < (n); i++)
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define twt int T;cin>>T;while(T--)
 
const int maxn = 1e6+3;
const ll mo = 1e9+7;
 
using namespace std;
int n,a[maxn];
ll s,kq=LLONG_MAX;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("INP.INP","r",stdin);
    freopen("OUT.OUT","w",stdout);
    #endif // ONLINE_JUDGE
    faster;
    cin >> n;
    f1(i,1,n) cin >> a[i];
    f1(i,1,n)
    {
        for (int j = i; j <= n; j++)
        {
            s+=a[i];
            kq = min(kq,s);
        }
    }
    cout << kq;
    return ( 0 ^ 0 );
}
 