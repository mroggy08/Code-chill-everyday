#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 5e5+3;
int n,k; ll x,ans[N][20],kq;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    cin >> n >> k;
    int lg = __lg(n)+2;
    f1(i,1,n) cin >> x,ans[i][0]=x;
    f1(j,1,lg) for (int i = 1; i+(1<<j)-1<=n; i++) ans[i][j] = __gcd(ans[i][j-1],ans[i+(1<<(j-1))][j-1]);
    f1(i,1,n-k+1)
    	kq = max(kq,__gcd(ans[i][__lg(k-1)],ans[(i+k-1) - (1<<(__lg(k-1))) + 1][__lg(k-1)]));
    cout << kq;
    return 0;
}
