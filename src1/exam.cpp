#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[1000003],S1,S2,P,S3,kq,e=1e9+7;
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], S1+=a[i], S2+=a[i]*a[i];
    P = (S1*S1-S2)/2;
    for (int i = 1; i <= n; i++){
        S3+=(a[i]*P-a[i]*a[i]*(S2-a[i]))%e;
    }
    cout << S3 << ' ';
    kq = S3/3;
    cout << kq;
    cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";
    return 0;
}
