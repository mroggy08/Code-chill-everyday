#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define ii pair<int,int>
using namespace std;
int n,p,a[10003];
ll f[10003];
ll dp(int st, int cur){
    if (st>n) return 0;
    if (f[st]!=0) return f[st];
    ll ans1 = 1e18, ans2 = 1e18;
    ans1 = min(ans1,dp(st+1,st) + (a[st]-cur)*(a[st]-cur));
    ans2 = min(ans2,dp(st+1,cur));
    return f[st] = min(ans1,ans2);
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
    cin >> n >> p;
    for (int i = 1; i<=n; i++) cin >> a[i];
    cout << dp(1,1);

    return 0;
}
