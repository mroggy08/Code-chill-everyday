#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e5+3;
ii a[N];
int n,m;
bool check(int d)
{
    ll vt = a[1].fi;
    int cnt = 1;
    for (int i = 1; i <= m; i++)
    {
        while (vt + d <= a[i].se)
        {
            vt = max(vt+d,(ll)a[i].fi);
            cnt++;
              if (cnt>=n) return 1;
        }

    }
    return 0;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> a[i].fi >> a[i].se;
    sort(a+1,a+m+1);
    ll l = 0, r = 2e9;
    while (r-l>1)
    {
        ll m = l + (r-l)/2;
        if (check(m)) l = m;
        else r = m;
    }
    cout << l;
    return ( 0 ^ 0);
}
