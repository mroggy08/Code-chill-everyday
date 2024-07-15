#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 1e3+3;
int n,K,a[N],val[N];
ll f[N][100003];
ll dp(int id, int tong){
    if (id > n) return 0;
    if (f[id][tong]!=-1) return f[id][tong];
    ll ans1 = 0, ans2 = 0;
    if (tong + a[id] <= K) ans1 = max(ans1,dp(id+1,tong + a[id]) + val[id]);
    ans2 = max(ans2,dp(id+1,tong));
    return f[id][tong] = max(ans2,ans1);
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> K;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= K; j++)
            f[i][j] = -1;
    cout << dp(1,0);
    return 0;
}
