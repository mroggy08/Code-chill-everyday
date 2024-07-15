#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
string s;
const int N = 1e5+5;
int r,kq,A[N],B[N],C[N];
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> s;
    int n = s.size();
    s = "#" + s;
    for (int i = 1; i <= n; i++){
        if (s[i]=='O') A[i] = A[i-1]+1; else A[i]=A[i-1];
        if (s[i]=='L') B[i] = B[i-1]+1; else B[i]=B[i-1];
        if (s[i]=='P') C[i] = C[i-1]+1; else C[i]=C[i-1];
    }
    //    r = 2;
    //    for (int i = 1; i <= n; i++){
    //        while (r<n){
    //            if ((A[r]-A[i-1]==3)||(B[r]-B[i-1]==3)||(C[r]-C[i-1]==3)){
    //                kq++;
    //            } else r++;
    //        }
    //    }
    //    cout << kq;
//    for (int i = 1; i <= n; i++){
//        cout << A[i] << ' ' << B[i] << ' ' << C[i] << '\n';
//    }

    return 0;
}
