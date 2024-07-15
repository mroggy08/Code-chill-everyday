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
int n,m,u,v;
int a[N][N],f[N][N],kq;
int tinh(int i,int j, int u, int v)
{
	return f[u][v] - f[u][j-1] - f[i-1][v] + f[i-1][j-1];
}
__ThanhDat()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    #define task "inp"
    if (fopen(task".inp","r")) {
    	freopen(task".inp","r",stdin);
    	freopen(task".out","w",stdout);
    }
    cin >> n >> m;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[i][j],f[i][j] = a[i][j] + f[i-1][j] + f[i][j-1] - f[i-1][j-1];
    for (int i = 1; i <= n; i++)
    {
    	for (int j = 1; j <= m; j++)
    	{
    		v = m;
    		kq = 0;
    		for (u = i; u <= n; u++)
    		{
    			// u chay tu i  toi n
    			// v tu m lui
    			while (tinh(i,j,u,v)!=0) v--;
    			// cout << v << ' ';
    			if (!tinh(i,j,u,v)){
    				// cout << i << ' ' << j << ' ' << u << ' ' << v << "a\n";
    				kq = max(kq,(u-i+1)*(v-j+1));
    			}
    		}
    		// if (v==0) cout << 0 << ' ';
    		// else {
    		// 	// cout << u << ' ' << v << ' ';
    		// 	cout << kq << ' ';
    		// }
    		// cout << (u-i+1)*(v-j+1) << ' ';
    		cout << kq << ' ';
    	}
    	cout << '\n';
    }

    
    return 0;
}