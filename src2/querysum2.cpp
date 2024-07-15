#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 1e5+5;
int n,q,a[N];
int loai,u,v;
ll x;
struct sv{
    ll val,lazy;
};
sv t[N*4];
void build(int id,int l, int r){
    if (l==r){
        t[id].val=a[l];return;
    }
    int m = (r+l)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    t[id].val=t[id*2].val+t[id*2+1].val;
}
void push(int id, int l, int r, int m){
    if (t[id].lazy){
        t[id*2].val += t[id].lazy*(m-l+1);
        t[id*2+1].val += t[id].lazy*(r-m);
        t[id*2].lazy += t[id].lazy;
        t[id*2+1].lazy += t[id].lazy;
        t[id].lazy=0;
    }
}
void up(int id, int l, int r, int u, int v, int vx){
    if (v<l||u>r) return;
    if (u<=l&&v>=r){
        t[id].val += vx*(r-l+1);
        t[id].lazy += vx;
        return;
    }
    int m = (r+l)/2;
    push(id,l,r,m);
    up(id*2,l,m,u,v,vx);
    up(id*2+1,m+1,r,u,v,vx);
    t[id].val=t[id*2].val+t[id*2+1].val;
}
ll get(int id, int l, int r, int u, int v){
    if (u>r||v<l) return 0;
    if (u<=l&&v>=r) return t[id].val;
    int m=(r+l)/2;
    push(id,l,r,m);
    return get(id*2,l,m,u,v)+get(id*2+1,m+1,r,u,v);
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for (int i=1;i<=n; i++) cin >> a[i];
    build(1,1,n);
    while (q--){
        cin >> loai >> u >> v;
        if (loai==1) {
            cin >> x;
            up(1,1,n,u,v,x);
        }
        else  cout << get(1,1,n,u,v) << '\n';
    }
    return 0;
}
