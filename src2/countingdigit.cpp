#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 1e6+3;

ll a,b;
vector<int> num;
ll f[20][20][2];
ll dp(int id, ll cnt, int bol, int dg){
    if (id==num.size()) return cnt;
    ll &res = f[id][cnt][bol];
    if (res!=-1) return res;
    res = 0;
    int z = 9;
    if (bol) z = num[id];
    for (int j = 0; j <= z; j++){
        if (bol==0) res += dp(id+1,cnt+j==dg,0,dg);
        else{
            if (j==z) {
                if (j==dg) res += dp(id+1,cnt+1,1,dg);
            } else {
                if (j==dg) res += dp(id+1,cnt+1,0,dg);
            }
        }
    }
    return f[id][cnt][bol] = res;
}
ll sol(ll k,int cs){
    num.clear();
    while (k>0){
        num.pb(k%10);
        k/=10;
    }
    reverse(num.begin(),num.end());
    memset(f,-1,sizeof f);
    return dp(0,0,1,cs);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
//    while (cin >> a >> b){
//        if (!a && !b) break;
//        for (int so = 0; so <= 9; so++) cout << sol(b,so) << ' ';
//        cout << '\n';
//    }
    cin >> a >> b;
    cout << sol(b,2);
    return 0;
}


