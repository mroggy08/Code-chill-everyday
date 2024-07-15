#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define Vii vector<ii>
#define fi first
#define se second
#define pri priority_queue <ii,Vii, greater<ii>>
#define pb push_back
#define f1(i,n,m) for (int i = (n); i <= (m); i++)
#define f2(i,n,m) for (int i = (n); i < (m); i++)
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define twt int T;cin>>T;while(T--)

using namespace std;

const int mod = 1e9+7;
const ll inf = 1e12;
int n,a[703],f[703][703];
int main()
{
    // freopen("INP.INP","r",stdin);
    // freopen("OUT.OUT","w",stdout);
    faster;
    cin >> n;
    f1(i,1,n) cin >> a[i];
    f1(i,1,n) f[i][i+1] = 0;
    for (int i = n; i >= 1; i--)
    {
    	for (int j = 1; j <= n; j++)
    	{
    		for (int d = i+1; d <= j-1; d++)
    			f[i][j] = max(f[i][j],f[i][d] + f[d][j] + a[d]*(a[i]+a[j]));
    	}
    }
    cout << f[1][n];
    return (0^0);
}