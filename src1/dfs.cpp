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
#define inf INT_MAX
using namespace std;
const int N = 1e6+3;
int kq,n,m,u,v,f[1003][1003];
char a[1003][1003];
int dx[4]{0,0,1,-1}, dy[4]{1,-1,0,0};
void dfs(int x, int y)
{
    f[x][y] = 1;
    f1(k,0,3)
    {
        int i2 = dx[k] + x, j2 = dy[k] + y;
        if (i2>0&&j2>0&&i2<=n&&j2<=m&&f[i2][j2]==-1&&a[i2][j2]=='.')
        {
            f[i2][j2] =  1;
            dfs(i2,j2);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define task "task"
    if (fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> m;
    f1(i,1,n) f1(j,1,m) cin >> a[i][j];
    f1(i,1,n) f1(j,1,m) f[i][j]=-1;
    f1(i,1,n) {
        f1(j,1,m)
        {
            if (f[i][j]==-1 && a[i][j]=='.')
            {
//                cout << i << ' ' << j << '\n';

                dfs(i,j);
                kq++;
            }
        }
    }
    cout << kq;
    return 0;
}

