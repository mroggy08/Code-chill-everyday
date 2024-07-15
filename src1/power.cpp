#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll kq;
int a,b,x,A[21],B[21];
void sang(int k){
    for (int i = 1; i <= k ;i++){
        if (i<=a){
            A[i%x]++;
            B[i%x]++;
        } else {
            B[i%x]++;
        }
    }
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> a >> b >> x;
    if (a>b) swap(a,b);
    sang(b);
    for (int i = 0; i < x; i++){
        cout << A[i] << ' ' << B[i] << '\n';
        kq += A[i]*B[i];
    }
    cout << kq;
    cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";
    return 0;
}
