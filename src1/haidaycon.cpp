#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define vi vector<int>
#define vii vector<ii>
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
#define task "task"
using namespace std;
ll n,k,a[1000003],s[1000003],g,h,kq;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    	freopen(task".inp","r",stdin);
    	freopen(task".out","w",stdout);

    cin >> n >> k;
    f1(i,1,n) cin >> a[i],s[i]=s[i-1]+a[i];
    for (int i = 1; i <= n-2*k+1; i++)
    {
    	g = s[i+k-1] - s[i-1];
    	for (int j = i+k; j <= n-k+1; j++)
    	{
    		h = s[j+k-1] - s[j-1];
    		// cout << g << ' ' << h << '\n';
    		kq = max(kq,abs(h-g));
    	}
    }
    cout << kq;

    return 0;
}
