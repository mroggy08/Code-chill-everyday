#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define f1(i,n,m) for (int i = n; i <= m; i++)
#define fz(i,n) for (int i = 0; i < n; i++)
#define __ThanhDat int main
using namespace std;
const int N = 6e3+3;
const ll mo = 1000000007;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int n,l,a[N],f[N],s[N];
__ThanhDat()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    #define task "inp"
    if (fopen(task".inp","r")) {
    	freopen(task".inp","r",stdin);
    	freopen(task".out","w",stdout);
    }
    cin >> n >> l;
    f1(i,1,n) cin >> a[i],s[i] = s[i-1] + a[i];
    f1(i,1,n)
    {
    	f[i] = l;
    	for (int j = i; j >= 1; j--){
    		if (s[i] - s[j-1] > l) break;
    		f[i] = min(f[i],max(f[j-1],l-s[i]+s[j-1]));
    	}
    }
    cout << f[n];
    
    return 0;
}