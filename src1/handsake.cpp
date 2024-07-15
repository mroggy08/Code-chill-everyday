#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e6+3;
int dx[]{-1,-1,-1,0,0,1,1,1},dy[]{-1,0,1,1,-1,-1,0,1};
char a[55][55];
int n,m,kq,d,tmp;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[i][j];
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
    	d = 0;
    	if (a[i][j]=='.')
    	{
    		for (int k = 0; k < 9; k++)
    		{
    			int i2 = i + dx[k], j2 = j + dy[k];
    			if (i2>0&&j2>0&&i2<=n&&j2<=m&&a[i2][j2]=='o') d++;
    		}
    	}
    	kq = max(kq,d);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j]=='o')
            {
                d = 0;
                for (int k = 0; k < 9; k++)
                {
                    int i2 = i + dx[k], j2 = j + dy[k];
                    if (i2>0&&j2>0&&i2<=n&&j2<=m&&a[i2][j2]=='o') d++;
                }
                tmp += d;
            }
        }
    }
    kq += tmp/2;
    cout << kq;
    return ( 0 ^ 0);
}
