#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e5+9;
int n,ok;
pair<ll,ll> a[N];
ll mau,tu,tmp;
void sol(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].first;
    for (int i = 1; i <= n; i++) cin >> a[i].second;
    tu = 1; mau = 1; ok = 0;
    for (int i = 1; i <= n; i++){
        if (a[i].second== 0){
            cout << "repeating\n";
            ok = 1;
            break;
        }
        tu *= a[i].first;
        mau *= a[i].second;
        tmp = __gcd(tu,mau);
        tu /= tmp;
        mau /= tmp;
    }
    if (ok) return;
    while (mau > 1 && mau%2==0) mau/=2;
    while (mau > 1 && mau%5==0) mau/=5;
    cout << (mau==1 ? "finite" : "repeating") << '\n';
}
int main()
{
//    if(fopen("fraction.inp","r")){freopen("fraction.inp","r",stdin);freopen("fraction.out","w",stdout);}
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tc;
    cin >> tc; while (tc--) sol();
    cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";
    return 0;
}
