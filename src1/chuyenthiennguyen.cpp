#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 1e6+6;
int n,a[N],m;
ii b[N];
long long int kq;
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    sort(a+1,a+n+1,greater<int>());
    for (int i = 1; i<= m; i++){
        cin >> b[i].fi;
        b[i].se = i;
    }
    sort(b+1,b+m+1);
    for (int i = 1; i <= n; i++){
        kq += a[i]*b[i].fi;
    }
    cout << kq << '\n';
    for (int i = 1; i <= n; i++)
        cout << b[i].se << ' ';


    return 0;
}
