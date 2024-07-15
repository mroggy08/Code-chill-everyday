#include <bits/stdc++.h>
#define ll long long
#define f1(i,n,m) for (int i=n; i<=m; i++)
#define fd(i,n) for (int i=0; i<n;i++)
#define fi first
#define se second
#define ii pair<int,int>
using namespace std;
const int N = 1e5+5;
ii a[N];
int n,c,kq;
bool cmd(ii a, ii b)
{
        return ((a.fi < a.se)&&(b.fi>b.se));
}
int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
       freopen("inp.inp","r",stdin);
       freopen("out.out","w",stdout);
        cin >> n >> c;
        f1(i,1,n)
                cin >> a[i].fi >> a[i].se;
        sort(a+1,a+n+1,cmd);
//        f1(i,1,n) cout << a[i].fi << ' ' << a[i].se << '\n';
        f1(i,1,n)
        {
                if (c>=a[i].fi) {
                        c+=a[i].se;
//                        cout << c << '\n';
                        kq++;
                }
        }
        cout << kq;
        return 0;
}


