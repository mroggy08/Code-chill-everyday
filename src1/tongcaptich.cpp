#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 1e6+6;
ll n,a[N];
int e=1e9+7;ll f[N][3];
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1; i<=n; i++) cin >> a[i];
    // f[i][1] = a[i]
    for (int i = 1; i <= n; i++) f[i][1] = (f[i-1][1] + a[i])%e;
    f[0][1] = 1;
    for (int i = 2; i <= n; i++){
        f[i][2] = (f[i-1][2] + (f[i-1][1]*a[i])%e)%e;
//        cout << f[i][2] << ' ';
    }
    cout << f[n][2];
    return 0;
}
