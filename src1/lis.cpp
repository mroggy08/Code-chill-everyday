#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,x,vt,kq,dp[1000003];
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> x;
        vt = lower_bound(dp+1,dp+kq+1,x) - dp;
        kq = max(kq,vt);
        dp[vt] = x;
    }
    cout << kq;

    cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";
    return 0;
}
