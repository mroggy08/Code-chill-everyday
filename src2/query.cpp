#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 2e5+3;
int m,n,q,a[N];
struct sv{
    ll val,lz;
};
sv t[N*4];
void build(int id, int l, int r){
    if (l==r){
        t[id].val=a[l];
        return;
    }
    int m = (r+l)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    t[id].val=t[id*2].val+t[id*2+1].val;
    cout << t[id].val << ' ' << t[id].val%m << '\n';
}
void push(int id, int l, int r){
    int mid = (r+l)>>1;
    if (t[id].lz){
        t[id*2].val = (t[id*2].val + t[id].lz*(m-l+1))%m;
        t[id*2+1].val = (t[id*2+1].val + t[id].lz*(r-m))%m;
        t[id*2].lz = (t[id*2].lz + t[id].lz)%m;
        t[id*2+1].lz = (t[id*2+1].lz + t[id].lz)%m;
        t[id].lz = 0;
    }
}
void upd(int id,int l,int r, int u, int v, int vx){
    if (u>r||v<l) return;
    if (u<=l && v>=r){
        t[id].val =  (t[id].val+vx*(r-l+1))%m;
        t[id].lz = (t[id].lz+vx)%m;
        return;
    }
    push(id,l,r);
    int m = (r+l)>>1;
    upd(id*2,l,m,u,v,vx);upd(id*2+1,m+1,r,u,v,vx);
    t[id].val=(t[id*2].val+t[id*2+1].val)%m;
}
ll get(int id, int l, int r, int u, int v){
        if (u>r||v<l) return 0;
    if (u<=l && v>=r){
        return t[id].val;
    }
    push(id,l,r);
    int m = (r+l)>>1;
    return (get(id*2,l,m,u,v) + get(id*2+1,m+1,r,u,v))%m;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    cin >> m >> n >> q;
    f1(i,1,n) cin >> a[i];
    build(1,1,n);
    cout << 3%2 << ' ' << 2%2 << '\n';
//    f1(i,1,4*n) cout << t[i].val << ' ';
//    cout << '\n';
    while (q--){
        int l,r,p,x;
        cin >> p >> l >> r;
        if (p==2){
//            cout << get(1,1,n,l,r) << '\n';
        } else {
            cin >> x;
            upd(1,1,n,l,r,x);
        }
    }
    return 0;
}


