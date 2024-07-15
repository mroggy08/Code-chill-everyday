#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
int n,m;
const ll e = 1e9+7;
const int N = 1e6+2;
ll f[N];
int a[N];
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int  i= 1; i <= n; i++) cin >> a[i];
    f[0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (j>=a[i]) f[j] = (f[j] + f[j-a[i]])%e;
        }
    }
    cout << f[m];


    return 0;
}
