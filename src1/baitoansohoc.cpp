#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,x,y;
ll calc(ll a, ll k){
    return a/k;
}
ll cal(ll x){
    return calc(b,x) - calc(a-1,x);
}
ll gcd(ll a, ll b){return __gcd(a,b);}
ll lcm(ll a, ll b){return (a*b)/gcd(a,b);}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> a >> b >> x >> y;
//    cout << cal(x) << ' ' << cal(y) << '\n';
    cout << cal(x) + cal(y) - cal(lcm(x,y));
    cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";
    return 0;
}
