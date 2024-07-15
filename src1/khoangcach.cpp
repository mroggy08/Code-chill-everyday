#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+9;
const int LG = 16;
const int inf = 1e9;
int n,m,q,a[N],b[N],c[N],vt,u,v,t[N][LG+3],lg;
void build(){
    for (int j = 1; j <= lg; j++){
        for (int i = 1; i + (1<<j)-1 <= n; i++){
            t[i][j] = min(t[i][j-1],t[i+(1<<(j-1))][j-1]);
        }
    }
}
int getm(int l, int r){
    int k = __lg(r-l+1);
    return min(t[l][k],t[r-(1<<k)+1][k]);
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int j = 1; j <= m; j++) cin >> b[j];
     sort(b+1,b+m+1);
    for (int i = 1; i <= n; i++){
        int l = upper_bound(b+1,b+m+1,a[i]) - b - 1;
        int r = lower_bound(b+1,b+m+1,a[i]) - b;
        t[i][0] = inf;
        if (l>0&&l<=m) t[i][0] = min(t[i][0], abs(b[l]-a[i]));
        if (r>0&&r<=m) t[i][0] = min(t[i][0], abs(b[r]-a[i]));
    }
    lg = __lg(n);
    build();
    while (q--){
        cin >> u >> v;
         cout << getm(u,v) << '\n';
    }
    cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";
    return 0;
}
