#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
ll t,d,q,i,k,tg1,tg2,kc1,kc2,kq;
int main()
{
//    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t >> d >> q >> i >> k;
//    tg1 = t/d;
//    tg2 = q/i;
//    tg1 += k;
//    tg2+=k;
    kc1 = t + k*d;
    kc2 = q + k*i;
    kq = abs(kc1-kc2);
    cout << kc1 << ' ' << kc2 << '\n';
    cout << kq;


    return 0;
}
