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
int n,u1,v1,u2,v2,s1,s2,xx,yy,dp[1003][1003];
char f[1003][1003];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define task "task"
    if (fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n;
    cin >> u1 >> v1 >> u2 >> v2;
    f1(i,1,n) f1(j,1,n) f[i][j] = '.';
    f[u1][v1] = f[u2][v2] = '*';
    f1(i,1,n)
    {
        if (u1+i>n || v1+i>n) break;
        f[u1+i][v1+i] = '*';
    }
    f1(i,1,n)
    {
        if (u1+i>n) break;
        f[u1+i][v1] = '*';
    }
    f1(i,1,n)
    {
        if (u1+i>n || v1-i<1) break;
        f[u1+i][v1-i] = '*';
    }
    f1(i,1,n)
    {
        if (v1-i<1) break;
        f[u1][v1-i] = '*';
    }
    f1(i,1,n)
    {
        if (u1-i<1 || v1-i<1) break;
        f[u1-i][v1-i] = '*';
    }
    f1(i,1,n)
    {
        if (u1-i<1) break;
        f[u1-i][v1] = '*';
    }
    f1(i,1,n)
    {
        if (u1-i<1 || v1+i>n) break;
        f[u1-i][v1+i] = '*';
    }
    f1(i,1,n)
    {
        if (v1+i>n) break;
        f[u1][v1+i] = '*';
    }
    // 2
    f1(i,1,n)
    {
        if (u2+i>n || v2+i>n) break;
        f[u2+i][v2+i] = '*';
    }
    f1(i,1,n)
    {
        if (u2+i>n) break;
        f[u2+i][v2] = '*';
    }
    f1(i,1,n)
    {
        if (u2+i>n || v2-i<1) break;
        f[u2+i][v2-i] = '*';
    }
    f1(i,1,n)
    {
        if (v2-i<1) break;
        f[u2][v2-i] = '*';
    }
    f1(i,1,n)
    {
        if (u2-i<1 || v2-i<1) break;
        f[u2-i][v2-i] = '*';
    }
    f1(i,1,n)
    {
        if (u2-i<1) break;
        f[u2-i][v2] = '*';
    }
    f1(i,1,n)
    {
        if (u2-i<1 || v2+i>n) break;
        f[u2-i][v2+i] = '*';
    }
    f1(i,1,n)
    {
        if (v2+i>n) break;
        f[u2][v2+i] = '*';
    }
//    f1(i,1,n) {
//        f1(j,1,n){
//            cout << f[i][j] << ' ';
//        }
//        cout << '\n';
//    }
    cin >> s1 >> s2 >> xx >> yy;
    dp[s1][s2] = 1;
    queue<ii> q;
    q.push({s1,s2});
    while (q.size())
    {
        int u1 = q.front().fi, u2 = q.front().se;
        q.pop();
//        if (u1==xx && y1==yy) break;
        f1(k,0,7)
        {
            int i2 = dx[k] + u1, j2 = dy[k] + u2;
            if (i2>0&&j2>0&&i2<=n&&j2<=n&&f[i2][j2]=='.'&&dp[i2][j2]==0)
            {
                dp[i2][j2] = 1;
                q.push({i2,j2});
            }
        }
    }
    if (dp[xx][yy]) cout << "YES"; else cout << "NO";
    return 0;
}

