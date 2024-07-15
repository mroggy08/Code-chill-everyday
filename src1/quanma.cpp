#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
int dx[]{1,1,2,2,-1,-1,-2,-2}, dy[]{2,-2,1,-1,2,-2,1,-1};
int n,m,x,y,xx,yy,d[1003][1003];
void bfs(){
    queue <ii> q;
    q.push({x,y});
    d[x][y]=0;
    while (q.size()){
        int u = q.front().first;
        int v = q.front().second;
        q.pop();
        for (int k = 0; k < 8; k++){
            int i2 = dx[k] + u, j2 = dy[k] + v;
            if (i2>0&&j2>0&&i2<=n&&j2<=m&&d[i2][j2]==0){
//                a[i2][j2]='#';
                d[i2][j2]=d[u][v] + 1;
                q.push({i2,j2});
            }
        }
    }
}
int main()
{
    if(fopen("quanma.inp","r")){freopen("quanma.inp","r",stdin);freopen("quanma.out","w",stdout);}
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> x >> y >> xx >> yy;
//    a[x][y] = '#';
//    for (int i = 1; i <= n; i++)
//        for (int j = 1; j <= m; j++)
//            a[i][j] = '.';
    bfs();
    if (d[xx][yy]==0){
        if (x==xx&&y==yy) cout << 0;
        else cout << -1;
    } else cout << d[xx][yy];


    cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";
    return 0;
}
