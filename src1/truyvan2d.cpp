#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 1e3+3;
int n,m,a[N][N],q,x1,x2,yy,yyy;
ll f[N][N];
ll get(int a1,int b1,int a2,int b2){
    return f[a2][b2] - f[a1-1][b2] - f[a2][b1-1] + f[a1-1][b1-1];
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++){
        cin >> a[i][j];
        f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + a[i][j];
    }
    cin >> q;
    while (q--){
        cin >> x1 >> yy >> x2 >> yyy;
        cout << get(x1,yy,x2,yyy) << '\n';
    }


    return 0;
}
