#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define Vii vector<ii>
#define X first
#define Y second
#define pri priority_queue <ii,Vii, greater<ii>>
#define pb push_back
#define f1(i,n,m) for (int i=(n);i<=(m);++i)
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;

const int N = 1e6+3;
// const int M = 1e3+3;
const int mod = 1e9+7;
ll a,b,mo;
ll F[2][2],M[2][2];
void cal(ll f[2][2], ll m[2][2])
{
	ll x,y,z,t;
    x = (f[0][0]*m[0][0]%mod + f[0][1]*m[1][0]%mod)%mod;
    y = (f[0][0]*m[0][1]%mod + f[0][1]*m[1][1]%mod)%mod;
    z = (f[1][0]*m[0][0]%mod + f[1][1]*m[1][0]%mod)%mod;
    t = (f[1][0]*m[0][1]%mod + f[1][1]*m[1][1]%mod)%mod;
    F[0][0] =x;F[0][1]=y;F[1][0]=z;F[1][1]=t;
}
void lt(ll f[2][2], ll n)
{
	if (n<=1) return;
	lt(f,n/2);
	cal(f,f);
	if (n&1) cal(f,M);
}
ll fibomatrix(ll n)
{
	F[0][0]=F[0][1]=F[1][0]=1; F[1][1]=0;
    M[0][0]=M[0][1]=M[1][0]=1; M[1][1]=0;
    if (n==0) return 0;
    lt(F,n-1);
    return F[0][0];
}
ll gcd(ll a, ll b)
{
	if (!b) return a;
	return gcd(b,a%b);
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("INP.INP","r",stdin);
    freopen("OUT.OUT","w",stdout);
    #endif // ONLINE_JUDGE
    fastIO;
    cin >> a >> b >> mo;
    // cout << fibomatrix(a) << ' ' << fibomatrix(b) << '\n';
    cout << gcd(fibomatrix(a),fibomatrix(b))%mo;
    return (0^0);
}
