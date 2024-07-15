#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 2e5+3;
int n,w,a[102];ll f[102][100002],b[102];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    cin >> n >> w;
    f1(i,1,n) cin >> a[i] >> b[i];
    f1(i,1,n){
        f1(j,1,w){
            f[i][j] = f[i-1][j];
            if (j>=a[i]) f[i][j] = max(f[i][j],f[i-1][j-a[i]] + b[i]);
        }
    }
    cout << f[n][w];
    return 0;
}
