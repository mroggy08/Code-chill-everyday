#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const ll e = 1e9+7;
int n;
ll s,f[500*501/2+3];
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    s = s*(s+1)/2;
    if (s&1) {
        cout << 0;
        return 0;
    }
        s/=2;
        f[0]=1;
        for (int i = 1; i <= n; ++i){
            for (int j = i*(i+1)/2; j>=i; --j){
                cout << j << ' ';
                f[j]=(f[j]+f[j-i])%e;
            }
            cout << '\n';
        }
        cout << f[s];



    return 0;
}
