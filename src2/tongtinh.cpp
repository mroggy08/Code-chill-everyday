#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 2e5+5;
int n,a[N],q,u,v;
ll t[N*4];
void build(int id, int l, int r){
    if (l==r){
        t[id]=a[l];
        return;
    }
    int m = (r+l)>>1;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    t[id]=t[id*2]+t[id*2+1];
}
ll get(int id, int l, int r,int u, int v){
    if (u>r||v<l) return 0;
    if (u<=l&&v>=r) return t[id];
    int m = (r+l)>>1;
    return get(id*2,l,m,u,v) + get(id*2+1,m+1,r,u,v);
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1,1,n);
    while (q--){
        cin >> u >> v;
        cout << get(1,1,n,u,v) << '\n';
    }

    return 0;
}
