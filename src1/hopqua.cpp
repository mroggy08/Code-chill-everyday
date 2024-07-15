#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6+3;
ll n,d,a[N],tam,r1,tam1,r2;
ll kq;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen("task.INP","r",stdin);
//    freopen("task.OUT","w",stdout);
    cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1,a+n+1);
//    for (int i = 1; i <= n-2; i++)
//    {
////        int l = lower_bound(a+i+1,a+n+1,a[i]+d) - a;
//        int r = upper_bound(a+i+1,a+n+1,a[i]+d) - a - 1;
//        int l1 = i+2;
//        int r1 = r-l1+1;
////        cout << r << ' ' << l1 << '\n';
////        kq += (r1*(r1+1))/2;
////        if (a[l] == a[i]+d) kq += (l-i-1); else
//////        cout << r << ' ';
////        kq += (r-i-1);
//    }
//    cout << kq;
    r2 = 3;
    for (int l = 1; l <= n-2; l++)
    {
        r1 = l+2;
//        r2 = r1;
//        cout << r2 << ' ';
        while (a[r2]-a[l] <= d && r2 < n) r2++;
        if (a[r2]-a[l] > d) r2--;
//        cout << r2 << ' ';
        tam = r2 - l - 1;
//        cout << tam1 << ' ';
//        cout << tam << ' ';
//        cout << tam << ' ';
        kq += tam*(tam+1)/2;
    }
    cout << kq;
    return 0;
}
