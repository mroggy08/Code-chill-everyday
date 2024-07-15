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
const int mo = 1e9;
int n,a[N],b[N];
ll kq;
ll lt(ll a, ll b)
{
    if (b==0) return 1;
    if (b==1) return a;
    ll s = lt(a,b/2);
    s = (s*s)%mo;
    if (b&1) s=(s*a)%mo;
    return s;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define task "task"
    if (fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n;
    f1(i,1,n) cin >> a[i]; f1(i,1,n) cin >> b[i];
    f1(i,1,n) kq = (kq+lt(a[i],b[i]))%mo;
    cout << kq;
    return 0;
}

