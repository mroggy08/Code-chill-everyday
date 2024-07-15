#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 2e5+5;
const int lg = 17;
int n,q,u,v;
ll x,a[N][lg+2];
ll get(int l, int r){
    int k = __lg(r-l+1);
    return min(a[l][k],a[r-(1<<k)+1][k]);
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> x;
        a[i][0] = x;
    }
    for (int j = 1; j <= lg;j++){
        for (int i = 1; i + (1<<j) - 1<=n; i++){
            a[i][j] = min(a[i][j-1],a[i+(1<<(j-1))][j-1]);
        }
    }
    while (q--){
        cin >> u >> v;
        cout << get(u,v) << '\n';
    }
    return 0;
}
