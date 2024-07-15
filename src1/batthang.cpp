#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define __ThanhDat int main
#define f1(i,n,m) for (int i = n; i <= m; i++)
#define fz(i,n) for (int i = 0; i < n; i++)
using namespace std;
const int N = 1e5+3;
const ll mo = 1000000007;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int n,a[N],ok[N],x,k;
ll f[N];
__ThanhDat()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    #define task "text"
    if (fopen(task".inp","r")) {
    	freopen(task".inp","r",stdin);
    	freopen(task".out","w",stdout);
    }
    cin >> n >> k;
    f1(i,1,k) cin >> x,ok[x]=1;
    f[0] = 1;
    for (int i = 1; i <= n; i++)
    {
    	if (ok[i]) f[i] = 0;
    	else f[i] = (f[i-1] + f[i-2])%mo;
    }
    cout << f[n];
    
    return 0;
}
