#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l,r;
ll cal(ll x){
    ll kq = 0;
    while (x>0){
        x>>=1; kq+=x;
    }
    return kq;
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> l >> r;
//    cout << cal(r) << ' ' << cal(l-1) << '\n';
    cout << cal(r) - cal(l-1);
    cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";
    return 0;
}
