#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+9;
const int lg = 17;
ll t[N][lg];
ll n,q,u,v,a[N],b[N],c[N];
ll gcd(ll a, ll b){return __gcd(a,b);}
ll get(int l, int r){
    int k = __lg(r-l+1);
    return gcd(t[l][k],t[r-(1<<k)+1][k]);
}
int main()
{
    if(fopen("seq.inp","r")){freopen("seq.inp","r",stdin);freopen("seq.out","w",stdout);}
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i], c[i] = abs(a[i]-b[i]);
    for (int i = 1; i <= n; i++) t[i][0] = c[i];
    for (int j = 1; j <= lg; j++){
        for (int i = 1; i + (1<<j) - 1 <= n; i++){
            t[i][j] = gcd(t[i][j-1],t[i+(1<<(j-1))][j-1]);
        }
    }
    while (q--){
        cin >> u >> v;
        cout << get(u,v) << '\n';
    }


    cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";
    return 0;
}
