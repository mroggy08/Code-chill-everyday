#include <bits/stdc++.h>
using namespace std;
int LG = 10,n,m,q,u,v,a[1003][1003],st[1003][11][1003][11],pr[1003][1003];
void build()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            pr[i][j] = pr[i-1][j] + pr[i][j-1] - pr[i-1][j-1] + a[i][j];
    for (int k = 0; k <= LG; k++)
    {
        for (int i=1; i + (1<<k)-1<=n; i++)
        {
            for (int l =0; l <= LG; l++)
            {
                for (int j = 1; j + (1<<l)-1 <= m; j++)
                {
                    if (k==0)
                    {
                        if (l==0){
                            st[i][0][j][0] = a[i][j];
                        }
                        else {
                            st[i][0][j][l] = max(st[i][0][j][l-1],st[i][0][j+(1<<(l-1))][l-1]);
                        }
                    } else {
                        st[i][k][j][l] = max(st[i][k-1][j][l],st[i+(1<<(k-1))][k-1][j][l]);
                    }
                }
            }
        }
    }
}
int getmax(int x, int y, int a, int b)
{
    int k = __lg(a-x+1), l = __lg(b-y+1);
    return max({st[x][k][y][l],
               st[x][k][b-(1<<l)+1][l],
               st[a-(1<<k)+1][k][b][l],
               st[a-(1<<k)+1][k][b-(1<<l)+1][l]});
}
int getsum(int x, int y, int a, int b)
{
    return pr[a][b] - pr[x-1][b] - pr[a][y-1] + pr[x-1][y-1];
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    build();
    cin >> q;
    while (q--)
    {
        cin >> u >> v;
        int kq = INT_MAX;
        for (int i = u; i <= n; i++)
            for (int j = v; j <= m; j++){
                int tam = getmax(i - u + 1, j - v + 1, i, j) * u * v - getsum(i-u+1,j-v+1,i,j);
                cout << getmax(i - u + 1, j - v + 1, i, j) * u * v << ' ' << getsum(i - u + 1, j - v + 1, i, j) << ' ' << tam << '\n';
                kq = min(kq,tam);
            }
        cout << kq << '\n';
    }
    return 0;
}


