#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define ii pair<int,int>
using namespace std;
int n,a[25003];
ll f[25003][3],kq;
ll dp(int id, int st){
    if (id>n) return 0;
    if (f[id][st]) return f[id][st];
    ll ans1 = -1e18, ans2 = -1e18;
    if (st>0) ans1 = dp(id+1,st-1) + a[id];
    ans2 = dp(id+1,2);
    return f[id][st] = max(ans1,ans2);
}
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
    kq = dp(1,2);
    cout << kq;
//    for (int i = 1; i <= n; i++){
//         for (int j = 1; j <= 2; j++){
//            cout << f[i][j] << ' ';
//         }
//         cout << '\n';
//    }
    return 0;
}

