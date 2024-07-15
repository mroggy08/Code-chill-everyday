#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 1e3+3;
int n,m,a[N][N],x,y,xx,yy;
ll s[N][N];
ll qr(int x,int y, int xx, int yy){
    return s[xx][yy] - s[xx][y-1] - s[x-1][yy] + s[x-1][y-1];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    cin >> n >> m;
    f1(i,1,n) f1(j,1,m) {
        cin >> a[i][j];
        s[i][j] = a[i][j] + s[i-1][j] + s[i][j-1] - s[i-1][j-1];
    }
    int q; cin >> q;
    while (q--){
        cin >> x >> y >> xx >> yy;
        cout << qr(x,y,xx,yy) << '\n';
    }

    return 0;
}

