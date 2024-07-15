#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 23;
int n,p[N],t[N];
long long k,l,r,kq;
bool check(long long d)
{
	ll s =0 ;
	for (int i = 1; i <= n; i++)
		if (d>=p[i])
			{
				ll tmp = (d - p[i])/t[i];
				s += 1 + tmp;
			}
	return s>=k;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("INP.INP","r",stdin);
    freopen("OUT.OUT","w",stdout);
    #endif // ONLINE_JUDGE
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> p[i] >> t[i];
    l = 1; r = (ll)1e20;
    while (l<=r)
    {
    	ll mid = (r+l)>>1;
    	if (check(mid)) kq = mid,r = mid - 1;
    	else l = mid + 1;
    }
    cout << kq;
    return ( 0 ^ 0);
}