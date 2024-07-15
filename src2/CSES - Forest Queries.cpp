#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 1e3+3;
int n,m,s[N][N],x1,x2,yy,yyy;
char c[N][N];
int get(int x1,int y1,int x2,int y2){
    return s[x2][y2] - s[x2][y1-1] - s[x1-1][y2] + s[x1-1][y1-1];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    cin >> n >> m;
    f1(i,1,n) f1(j,1,n){
        cin >> c[i][j];
        if (c[i][j]=='*'){
            s[i][j] = 1+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        } else {
               s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        }
    }
    while (m--){
        cin >> x1 >> yy >> x2 >> yyy;
        cout << get(x1,yy,x2,yyy) << '\n';
    }

    return 0;
}


