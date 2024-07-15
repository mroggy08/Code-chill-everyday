#include <bits/stdc++.h>
#define ll long long
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
    for (int i = 1; i <= n; i++){
        cin >> x;
        d[x]++;
        mx = max(mx,x);
    }
    for (int i = 1; i <= N; i++){
        f[i] = f[i-1] + d[i];
    }
    for (int i = 1; i <= mx; i++){
        if (d[i]){
            if (d[i]>=3) kq += 1LL*(d[i]*(d[i]-1)*(d[i]-2))/6;
            if (d[i]>=2) kq += 1LL*d[i]*(d[i]-1)/2*(f[2*i-1]-d[i]);
        }
    }
    cout << kq;
    return 0;
}
