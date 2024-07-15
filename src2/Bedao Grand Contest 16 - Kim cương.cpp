#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 1e6+5;
int n,res,kq;
ii a[N];
map <ii,int> f;
int dx[12]{-1,-1,-1,0,0,0,0,0,1,1,1,2},dy[12]{-1,0,1,-2,-1,0,1,2,-1,0,1,0};
int sol(int x, int y){
    int tam = f[{x,y}];
    for (int k = 0; k < 12; k++){
        int i2 = x+dx[k],j2=y+dy[k];
        tam += f[{i2,j2}];
    }
    return tam;
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> u >> v >> val;
        a[i].fi = u; a[i].se = v;
        f[{a[i].fi,a[i].se}] = val;
    }
    for (int i = 1; i <= n; i++){
        res = sol(a[i].fi,a[i].se);
        kq = max(kq,res);
    }

    return 0;
}
