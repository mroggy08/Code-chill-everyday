#include <bits/stdc++.h>
using namespace std;
const int c=1e3+5,mod=1e8+5;
int n,m,f[c][c];
char a[c][c];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)  cin>>a[i][j];
	}
	f[1][1]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='.')
			{
				if(i>1) f[i][j]+=(f[i-1][j])%mod;
				if(j>1) f[i][j]+=(f[i][j-1])%mod;
				f[i][j]%=mod;
			}
			else f[i][j]=0;
		}
		cout<<f[n][m];
		return 0;
	}
}
