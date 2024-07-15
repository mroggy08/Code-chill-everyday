#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll tc,n,k,mo,kq,m;
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> tc; while (tc--){
        cin >> n >> k;
        m = k/(n-1);
        if (m*(n-1)!=k) {
            mo = k%(n-1);
            kq = n*m + mo;
        } else {
//            cout << n << ' ' << m << ' ';
            kq =  n*m-1;
        }
        cout << kq << '\n';

    }


    cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";
    return 0;
}
