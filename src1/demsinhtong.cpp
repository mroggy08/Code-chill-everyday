#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define ii pair<int,int>
using namespace std;
int n,x,a[102];
ll f[102][10003];
const ll mo = 1000000007;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    #define task "inp"
    if (fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> a[i];
    f[0][0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= x; j++){
            if (j >= a[i]) f[i][j] = (f[i-1][j-a[i]] + f[i-1][j])%mo;
            else f[i][j] =  f[i-1][j];
        }
    }
    cout << f[n][x];
    return 0;
}
