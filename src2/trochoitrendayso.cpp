#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const ll inf = 1e18;
const int N = 1e3+3;
int n,k,a[N],b[N];
ll f[N][N][6];
ll dp(int i, int j, int step){
    if (step==k) return 0;
    if (i>n||j>n) return INT_MIN;
    if (f[i][j][step]!=-1) return f[i][j][step];
//    ll &res=f[i][j][step];
    ll res;
    res = max(dp(i+1,j,step),dp(i,j+1,step));
    res = max(res,dp(i+1,j+1,step+1) + 1LL*a[i]*b[j]);
    return f[i][j][step]=res;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    cin >> n >> k;
    f1(i,1,n) cin >> a[i];
    f1(i,1,n) cin >> b[i];
    memset(f,-1,sizeof f);
    cout << dp(1,1,0);
    return 0;
}


