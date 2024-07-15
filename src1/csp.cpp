#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[1000003],k,r; ll kq;
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1,a+n+1);
    for (int i = 1; i <= n; i++){
        k = m - a[i];
        r = upper_bound(a+i+1,a+n+1,k) - a - 1;
        kq += r-i;
    }
    cout << kq;


    cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";
    return 0;
}
