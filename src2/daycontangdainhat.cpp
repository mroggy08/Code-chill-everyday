#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 1e6+3;
int n,x,vt,kq,dp[N];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    cin >> n;
    f1(i,1,n){
    	cin >> x;
    	vt = lower_bound(dp+1,dp+kq+1,x) - dp;
    	kq=  max(kq,vt);
    	dp[vt] = x;
    }
    cout << kq;
    return 0;
}

