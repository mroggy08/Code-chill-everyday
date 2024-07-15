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
using namespace std;
const int N = 1e6+3;
int n,a[N],f[N],k;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("task.inp","r",stdin);
    freopen("task.out","w",stdout);
    cin >> n >> k;
    f1(i,1,n) cin >> a[i];
    if (k==0)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if ((a[i] > a[j]) && (a[i] - a[j] == i - j))
                    f[i] = max(f[i],f[j] + a[i]);
            }
        }
        f1(i,1,n) cout << f[i] << ' ';
    }
//    else if (k==1)
//    {
//
//    }
    return 0;
}

