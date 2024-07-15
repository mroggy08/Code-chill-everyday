#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define vi vector<int>
#define vii vector<ii>
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
#define bit(i,x) ((x>>i)&1)
#define bp __builtin_popcount
using namespace std;
const int N = 1e2+3;
const int inf = 1e9;
int n,a[4],u,v,w,kq=1e9,f[N][N];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define task "task"
    if (fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n;
    f1(i,0,3) cin >> a[i];
    f1(i,1,n) f1(j,1,n) f[i][j] = 1e9;
    f1(i,1,n) f[i][i] = 0;
    while (cin>>u>>v>>w)
    	f[u][v] = f[v][u] = min(f[u][v],w);
    f1(k,1,n) f1(i,1,n) f1(j,1,n) f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
    do{
    	f1(i,1,n)
    		f1(j,1,n)
    			{
    				kq = min(kq,f[i][a[0]] + f[j][a[2]] + f[j][a[1]] + f[i][a[3]] + f[i][j]);

    			}
    	// cout << kq << '\n';
    		// cout << a[i] << ' ' << f[1][a[i]] << '\n';
    		// cout << '\n';
    } while (next_permutation(a,a+4));
    cout << kq ;
    return 0;
}
