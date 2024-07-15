#include <bits/stdc++.h>
#define ll long long
#define f1(i,n,m) for (int i=n; i<=m; i++)
#define fd(i,n) for (int i=0; i<n;i++)
#define fi first
#define se second
using namespace std;
const int N = 2e5+5;
int n,m,a[N],r=INT_MIN,l=1,kq;
bool check(int mid)
{
    int d=0;
    f1(i,1,n)
        if (a[i]>mid) d+=(a[i]/mid-1)+(a[i]%mid!=0);
    return d<=m;
}
int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
//        freopen("inp.inp","r",stdin);
//        freopen("out.out","w",stdout);
       cin >> n >> m;
       f1(i,1,n) {
                cin >> a[i];
                r = max(r,a[i]);
       }
//       cout << l << ' ' << r;
       while (l<=r)
       {
               int mid = (r+l)>>1;
               if (check(mid)) kq=mid,r = mid - 1;
               else {
                // kq = mid;
                l = mid+1;
               }
       }
       cout << kq;
        return 0;
}


