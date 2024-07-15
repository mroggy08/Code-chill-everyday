#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+6;
int n,f[N],kq;
string s;
int main()
{
//    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> s;
    s = " " + s;
    for (int i = 1; i <= n;i++){
        if (s[i]=='i'||s[i]=='c'||s[i]=='t') f[i] = f[i-1] + 1;
            else f[i] = 0;
    }
    for (int i = 1; i <= n; i++) kq=max(kq,f[i]);
    cout << kq;


    cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";
    return 0;
}
