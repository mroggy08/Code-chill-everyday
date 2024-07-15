#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define vi vector<int>
#define vii vector<ii>
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
int n,m,dx[4]{1,-1,0,0},dy[4]{0,0,1,-1};
char a[103][103];
int res,f[103][103],x,y,ok;
void bfs()
{
    queue <ii> q;
    q.push({x,y});
    f[x][y] = 0;
    res = 0;
    while (q.size())
    {
        int u = q.front().fi, v = q.front().se;
//        cout << u << ' ' << v << '\n';
        q.pop();
        f1(k,0,3)
        {
            int i2 = u + dx[k], j2 = v + dy[k];
            if (i2>0&&j2>0&&i2<=n&&j2<=m&&f[i2][j2]==-1&&a[i2][j2]=='.')
            {
                f[i2][j2] = f[u][v] + 1;
                q.push({i2,j2});
                res = max(res,f[i2][j2]);
            }
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
    if (n>=m){
        f1(i,1,n)
        {
            if (ok==0){
                f1(j,1,m)
                {
                    if (a[i][j]=='.'){
                        x = i;
                        y = j;
                        ok = 1;
                        break;
                    }
                }
            }
            else break;
        }

    }
    else {
        f1(j,1,m)
        {
            if (!ok)
            {
                f1(i,1,n)
                {
                    if (a[i][j]=='.')
                    {
                        x = i;
                        y = j;
                        ok = 1;
                        break;
                    }
                }
            }
            else break;
        }
    }
    memset(f,-1,sizeof f);
//    cout << x << ' ' << y << '\n';
    bfs();
    cout << res;
    return 0;
}
