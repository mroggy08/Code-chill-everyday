#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[1000003];
ll f[1000003][4],e=1e9+7;
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++){
        f[i][1] = f[i-1][1] + a[i];
    }
    for (int i = 1; i <= n; i++){
        for (int j = 2; j <= 3; j++){
            f[i][j] = (f[i-1][j] + f[i-1][j-1]*a[i])%e;
        }
    }
    cout << f[n][3];


    cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";
    return 0;
}
