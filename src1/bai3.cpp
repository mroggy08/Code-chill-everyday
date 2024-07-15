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
const int N = 4e5+3;
const int mo = 1e9+7;
int n,a[N],l,r,x,y,k,q,mi=INT_MAX,ma=INT_MIN;
ll t[N*4];
ll lt(ll a, ll b)
{
    if (b==0) return 1;
    if (b==1) return a;
    ll s = lt(a,b/2);
    s=(s*s)%mo;
    if (b&1) s=(s*a)%mo;
    return s;
}
void sub1()
{
    ll tich = 1;
    for (int i = l; i <= r; i++)
    {
        if (a[i] >= x && a[i] <= y)
            tich = (tich*a[i])%mo;
    }
    cout << tich << '\n';
}
void sub2()
{
    ll tich = 1;
    for (int i = l; i <= r; i++)
    {
       if (a[i]>=x && a[i]<=y)  tich = (tich*lt(a[i],k))%mo;
    }
    cout << tich << '\n';
}
void build(int id, int l, int r)
{
    if (l==r){
        t[id]=a[l];
        return;
    }
    int m=(r+l)>>1;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    t[id]=(t[id*2+1]*t[id*2])%mo;
}
ll get(int id, int l, int r, int u, int v){
    if (u>r || v<l) return 1;
    if (u<=l&&v>=r) return t[id];
    int m = (r+l)>>1;
    return (get(id*2,l,m,u,v)*get(id*2+1,m+1,r,u,v))%mo;
}
void dacbiet()
{
    ll kq1 = get(1,1,n,l,r);
    ll g = lt(kq1,k);
    cout << g << '\n';
}
void sub()
{
    ll tich=1;
    for (int i = l; i <= r; i++)
    {
        if (a[i]>=x && a[i]<=y) tich = (tich*a[i])%mo;
    }
    cout << tich << '\n';
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//    freopen("task.inp","r",stdin);
//    freopen("task.out","w",stdout);
    cin >> n >> q;
    f1(i,1,n) cin >> a[i],mi = min(a[i],mi),ma=max(ma,a[i]);
    build(1,1,n);
    if (n<=2000)
    {
        while (q--)
        {
            cin >> l >> r >> x >> y >> k;
            if (k==1) sub1();
            else sub2();
        }
    }
    else
    {
        while (q--)
        {
            cin >> l >> r >> x >> y >> k;
            if (mi >= x && ma <= y) dacbiet();
            else sub();
        }
    }
    return 0;
}

