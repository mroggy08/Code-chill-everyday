#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define ii pair<int,int>
using namespace std;
int n,a[25003],i,ok[25003];
ll f[25003],kq;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    #define task "inp"
    if (fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++){
        f[i] = max({f[i-1],f[i-2] + a[i],f[i-3]+a[i-1]+a[i]});
    }
//    cout << f[n];
    i = n;
    while (i > 0){
        if (f[i]==f[i-1]) {
            i--;
            continue;
        }
        else if (f[i] == f[i-2] + a[i]){
            ok[i] = 1;
            i--;
        }
        else {
            ok[i] = 1;
            ok[i-1] = 1;
            i-=2;
        }
        i--;
    }
    cout << f[n] << '\n';
    for (int i = 1; i <= n; i++) if (ok[i]) cout << i << ' ';
    return 0;
}


