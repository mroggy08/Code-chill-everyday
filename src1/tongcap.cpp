#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define __ThanhDat int main
using namespace std;
const int N = 5e4+3;
const ll mo = 1000000007;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
 
int n,q,a[N],m,k,kq;
__ThanhDat()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    #define task "inp"
    if (fopen(task".inp","r")) {
    	freopen(task".inp","r",stdin);
    	freopen(task".out","w",stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1,a+n+1);
	cin >> q;
	while (q--)
	{
		cin >> m;
		k = n;
		kq = 0;
		for (int i = 1; i < n; i++)
		{
			while (k > i && a[k] + a[i] > m) k--;
			if (k>i)kq += k - i;
		}
		cout << kq << '\n';
	}
    
    return 0;
}