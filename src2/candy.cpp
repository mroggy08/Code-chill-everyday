#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 1e6+3;
int n,ans,res;
ii a[N],cur;
bool cmd(ii a, ii b){
    if (a.fi==b.fi) return a.se>b.se;
    return a.fi < b.fi;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    cin >> n;
    f1(i,1,n) cin >> a[i].fi >> a[i].se;
    sort(a+1,a+n+1,cmd);
    cur = a[1];
    ans = 1;
//    f1(i,1,n) {
//        cout << a[i].fi << ' ' << a[i].se << '\n';
//    }
    f1(i,2,n){
        if (a[i].fi > cur.se) {
            cur = a[i];
            res = max(res,ans);
            ans = 1;
        }
        else if (a[i].fi <= cur.se){
            ans++;
            res = max(res,ans);
            cur = a[i];
        }
    }
    cout << res;
    return 0;
}

