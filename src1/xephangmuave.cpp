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
const int N = 6e4+3;
int n,a[N],b[N];
ll f[N];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define task "task"
    if (fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n;
    f1(i,1,n) cin >> a[i];
    f1(i,1,n-1) cin >> b[i];
    f[1] = a[1];
    f[2] = min(b[1],a[1]+a[2]);
    f1(i,3,n)
    {
        f[i] = min(f[i-1]+a[i],f[i-2]+b[i-1]);
    }
    cout << f[n];
    return 0;
}

