#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int naxn = 1e5+5;
const int maxn = 5e5+5;
int N,K,a[naxn];
ll f[naxn][maxn];
ll dp(int id, int lucchien){
    if (id==N){
        if(lucchien>0) return -1;
        return 0;
    }
    if (f[id][lucchien]!=-1) return f[id][lucchien];
    ll kq=0;
    if (lucchien < K && id+lucchien<N) kq=max(kq,dp(id+1,lucchien+1) + a[id+1]);
    if (lucchien==0 && id<N) kq=max(kq,dp(id+1,0));
    if (lucchien>0 && id+lucchien<=N)kq=max(kq,dp(id+lucchien,0));
    return f[id][lucchien] = kq;
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i <= N; i++){
        for (int j = 0; j<=K; j++){
            f[i][j] = -1;
        }
    }
    cout << dp(1,0);
    return 0;
}
