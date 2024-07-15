#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 2e5+3;
struct sv{
    ll val,lz1,lz2;
};
sv t[N*4];
int n,q,a[N],p,u,v,vx;
void build(int id, int l, int r){
    if (l==r){
        t[id].val=a[l];return;
    }
    int m = (r+l)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    t[id].val=t[id*2].val+t[id*2+1].val;
}
void push(int id, int l, int m, int r){
    if (t[id].lz2){
        ll value = t[id].lz2;
        t[id*2].val = value*1LL*(m-l+1);
        t[id*2+1].val = value*1LL*(r-m);
        t[id*2].lz2 = t[id*2+1].lz2 = value;
        t[id*2].lz1 = t[id*2+1].lz1 = 0;
        t[id].lz2=0;
    }
    if (t[id].lz1){
        ll value = t[id].lz1;
        t[id*2].val += value*1LL*(m-l+1);
        t[id*2+1].val += value*1LL*(r-m);
        t[id*2].lz1 +=  value;
        t[id*2+1].lz1 += value;
        t[id].lz1 = 0;
    }
}
void up1(int id, int l, int r, int u, int v, int gt){
    if (u>r||v<l) return;
    if (u<=l&&v>=r) {
        t[id].val+=gt*1LL*(r-l+1);
        t[id].lz1+=gt;
        return;
    }
    int m=(r+l)/2;
    push(id,l,m,r);
    up1(id*2,l,m,u,v,gt);
    up1(id*2+1,m+1,r,u,v,gt);
    t[id].val=t[id*2].val+t[id*2+1].val;
}
void up2(int id, int l, int r, int u, int v, int gt){
    if (u>r||v<l) return;
    if (u<=l&&v>=r) {
        t[id].val=gt*1LL*(r-l+1);
        t[id].lz1=0;
        t[id].lz2=gt;
        return;
    }
    int m=(r+l)/2;
    push(id,l,m,r);
    up2(id*2,l,m,u,v,gt);
    up2(id*2+1,m+1,r,u,v,gt);
    t[id].val=t[id*2].val+t[id*2+1].val;
}
ll get(int id, int l, int r, int u, int v){
    if (u>r||v<l) return 0;
    if (u<=l&&v>=r){
        return t[id].val;
    }
    int m = (r+l)>>1;
    push(id,l,m,r);
    return get(id*2,l,m,u,v) + get(id*2+1,m+1,r,u,v);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    cin >> n >> q;
    f1(i,1,n) cin >> a[i];
    build(1,1,n);
    while (q--){
        cin >> p >> u >> v;
        if (p==3) cout << get(1,1,n,u,v) << '\n';
        else {
            cin >> vx;
            if (p==1) up1(1,1,n,u,v,vx);
            else up2(1,1,n,u,v,vx);
        }
    }
    return 0;
}

