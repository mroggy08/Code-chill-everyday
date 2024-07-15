#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 1e5+5;
const int M = 5e2+5;
int n,k,a[N];
int  f[N][M];
int  dp(int id, int lucchien){
    if (id==n){
        if(lucchien==0) return 0;
        return -1e9;
    }
    if (f[id][lucchien]!=-1e9) return f[id][lucchien];
    int  kq=-1e9;
    if (lucchien==0 && id<n) kq=max(kq,dp(id+1,0));
    if (lucchien>0 && id+lucchien<=n)kq=max(kq,dp(id+lucchien,0));
    if (lucchien < k && id+lucchien<n) kq=max(kq,dp(id+1,lucchien+1) + a[id+1]);
    return f[id][lucchien] = kq;
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i <= n; i++){
        for (int j = 0; j<=k; j++){
            f[i][j] = -1e9;
        }
    }
    cout << dp(0,0);
    return 0;
}

