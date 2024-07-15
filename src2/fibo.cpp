#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 1e6+3;
const int mo = 1e9+7;
ll n,fb[2][2],mt[2][2];
void cal(ll f[2][2], ll m[2][2]){
    ll a,b,c,d;
    a = (f[0][0]*m[0][0]%mo + f[0][1]*m[1][0]%mo + mo)%mo;
    b = (f[0][0]*m[0][1]%mo + f[0][1]*m[1][1]%mo + mo)%mo;
    c = (f[1][0]*m[0][0]%mo + f[1][1]*m[1][0]%mo + mo)%mo;
    d = (f[1][0]*m[0][1]%mo + f[1][1]*m[1][1]%mo + mo)%mo;
    fb[0][0] =a;fb[0][1]=b;fb[1][0]=c;fb[1][1]=d;
}
void lt(ll f[2][2], ll n){
    if (n<=1) return;
    lt(f,n/2);
    cal(f,f);
    if (n&1) cal(f,mt);
}
ll fibo(ll n){
    if (n<=0) return n;
    fb[0][0] = fb[0][1] = fb[1][0] = 1; fb[1][1] = 0;
    mt[0][0] = mt[0][1] = mt[1][0] = 1; mt[1][1] = 0;
    lt(fb,n-1);
    return fb[0][0];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    while (cin>>n){
        cout << fibo(n) << '\n';
    }
    return 0;
}

