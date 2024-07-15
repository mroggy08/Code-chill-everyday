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
const int N= 1e3+3;
int f[N][N],n,m,dx[4]{1,-1,0,0},dy[4]{0,0,1,-1},ok;
char a[N][N];
vector <ii> dd;
ii vt;
void dfs(int x, int y)
{
    if (x<1||y<1||x>n||y>m) {
        ok = 1; return;
    }
    if (f[x][y] || a[x][y]=='X') return;
    f[x][y] = 1;
    f1(k,0,3)
    {
        int i2 = x + dx[k], j2 = y + dy[k];
        dfs(i2,j2);
        if (ok)
        {
            dd.pb({x,y});
            return;
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
    f1(i,1,n) f1(j,1,m){
        cin >> a[i][j];
        if (a[i][j]=='E') vt={i,j};
    }
    dfs(vt.fi,vt.se);
    if (ok){
        cout << "YES\n";
        reverse(dd.begin(),dd.end());
        for (auto it : dd) cout << it.fi << ' ' << it.se << '\n';
    }

    return 0;
}
