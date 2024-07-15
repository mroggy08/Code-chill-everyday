#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e10;
const int N = 4e2+5;
int n,k,h[N],mx;
ll s,f[N][N];
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= k; j++) f[i][j] = inf;
    }
    f[1][0] = 0;
    for (int i = 2; i <= n; i++){
        s = 0, mx = 0;
        for (int j = 1; j <= i; j++){
            s += h[j];
            mx = max(mx,h[j]);
        }
        f[i][0] = mx*i - s;
    }
    for (int i = 2; i <= n; i++){
        for (int d = 1; d <= k; d++){
            s = 0, mx = 0;
            for (int j = i; j > 1; j--){
                s+=h[j];
                mx = max(mx,h[j]);
                f[i][d] = min(f[i][d],f[j-1][d-1]+mx*(i-j+1)-s);
            }
        }
    }
//    for (int i = 1; i <= n; i++){
//        for (int j = 0; j <= k; j++){
//            cout << f[i][j] << ' ';
//        }
//        cout << '\n';
//    }
    cout << f[n][k];

    cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";
    return 0;
}
