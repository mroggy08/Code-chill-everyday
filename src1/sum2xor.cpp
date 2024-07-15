#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mo = 998244353;
const int md = 1e9+7;
ll a,b,s,aa,bb,kq;
ll Pow(ll a, ll b){
    if (b==0) return 1;
    if (b==1) return a;
    ll s = Pow(a,b/2);
    s=(s*s)%mo;
    if (b&1) s=(s*a)%mo;
    return s;
}
ll lt(ll a, ll b){
    string s = to_string(b);
    ll kq;
    if (s.size()==1){
        kq = Pow(a,b);
    } else {
        kq = Pow(a,s[0]-'0');
        for (int i = 1; i < s.size(); i++){
            kq = Pow(kq,10)*Pow(a,s[i]-'0');
        }
    }
    return kq;
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> a >> b;
    s = (a-1)*a/2;
    aa = (lt(2,b)-1)*lt(2,b)/2;
    bb = b*(a-1);
    kq = (s*aa*lt(2,b)*lt(2,bb));
    cout << kq;
    cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";
    return 0;
}
