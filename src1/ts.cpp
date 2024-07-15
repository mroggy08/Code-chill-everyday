#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
#define __ThanhDat int main

using namespace std;

const int maxd = 1e2;
const int maxn = maxd*maxd;
const ll mo = 1000000007;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int n,m,ok;
int cot[maxd+5];char a[maxd+3][maxd+3];
int kq,dp[maxd+5];
__ThanhDat()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define task "inp"
//    if (fopen(task".inp","r")) {
//    	freopen(task".inp","r",stdin);
//    	freopen(task".out","w",stdout);
//    }
    cin >> n >> m;
    f1(i,1,n) f1(j,1,m) cin >> a[i][j];
    f1(j,1,m) {
    	ok = 0;
    	if (a[1][j]=='o')
    	{
    		f1(i,2,n)
    			if (a[i][j]=='.') ok = 1;
    		if (!ok) cot[j] = 1;
    	}
    }
    f1(i,1,m) cout << cot[i] << ' ';
    f1(i,1,m){
    	if (a[1][i]=='o' || cot[i]==0) dp[i] = 0;
    	else {
    		if (a[1][i]==a[1][i-1]&&cot[i]) dp[i] = dp[i-1]+1;
    		else dp[i] = 1;
    	}
    }
    f1(i,1,m) kq = max(kq,dp[i]);
    cout << kq;
    cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return (0 ^ 0);
}
