#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,mo;
const ll md = 1e9+7;
ll F[2][2],M[2][2];
ll gcd(ll a, ll b){
    return __gcd(a,b);
}
void cal(ll f[2][2], ll m[2][2]){
    ll x,y,z,t;
    x = (f[0][0]*m[0][0] + f[0][1]*m[1][0])%md;
    y = (f[0][0]*m[0][1] + f[0][1]*m[1][1])%md;
    z = (f[1][0]*m[0][0] + f[1][1]*m[1][0])%md;
    t = (f[1][0]*m[0][1] + f[1][1]*m[1][1])%md;
    F[0][0] =x;F[0][1]=y;F[1][0]=z;F[1][1]=t;
}
void lt(ll f[2][2], ll n){
    if (n<=1) return;
    lt(f,n/2);
    cal(f,f);
    if (n&1) cal(f,M);
}
ll fibo(ll n)
{
	F[0][0]=F[0][1]=F[1][0]=1; F[1][1]=0;
    M[0][0]=M[0][1]=M[1][0]=1; M[1][1]=0;
    if (n==0) return 0;
    lt(F,n-1);
    return F[0][0];
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> a >> b >> mo;
    ll u = gcd(a,b);
    ll fb = fibo(u);
    cout << fb%mo;
    cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";
    return 0;
}
