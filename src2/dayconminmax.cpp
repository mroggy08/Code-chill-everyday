#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 1e6+3;
int n,a[N],mx=INT_MIN,mi=INT_MAX,kq=INT_MAX;
vector<ii> dp;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    cin >> n;
    f1(i,1,n) {
        cin >> a[i];
        mx = max(mx,a[i]);
        mi = min(mi,a[i]);
    }
    f1(i,1,n){
        if (a[i]==mi || a[i]==mx){
            dp.pb({a[i],i});
        }
    }
    for (int i = 1; i < dp.size(); i++){
        if (dp[i].fi != dp[i-1].fi){
//            cout << dp[i-1].se << ' ' << dp[i].se << '\n';
            kq = min(kq,dp[i].se - dp[i-1].se+1);
        }

    }
    cout << kq;

    return 0;
}


