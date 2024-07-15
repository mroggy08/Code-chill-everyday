#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 1e5+5;
int n,q,a[N],val,ty,u,v;
struct sv{
    ll gt,lz;
};
sv t[N*4];
void build(int )
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1,1,n);
    while (q--){
        cin >> ty >> u >> v;
        if (ty==1){
            cin >> val;
            up(1,1,n,u,v,val);
        } else cout << get(1,1,n,u,v) << '\n';
    }


    return 0;
}

