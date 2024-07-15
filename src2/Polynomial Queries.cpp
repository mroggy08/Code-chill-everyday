#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 2e5+3;
int n,q,a[N],p,u,v;
struct sv{
    ll val,lazy1,lazy2;
};
sv t[N*4];
void build(int id, int l, int r){
    if (l==r){
        t[id]=sv(a[l],0,0);
        return;
    }
    int m = (r+l)/2;
    build(id*2,l,m);build(id*2+1,m+1,r);
    t[id].val=t[id*2].val+t[id*2+1].val;
}
void push(int id, int l,int m, int r){
    t[id*2].val += (m-l+1)*(m-l+2)/2*t[id].lazy1 + t[id].lazy2*(m-l+1);
    t[id*2].lazy1 += t[id].lazy1;
    t[id*2].lazy2 += t[id].lazy2;
    t[id*2+1].val += (r-m)*(r-m+1)/2*t[id].lazy1 + (t[id].lazy2 + t[id].lazy1*(m-l+1))*(r-m);
    t[id*2+1].lazy1 += t[id].lazy1;
    t[id*2+1].lazy2 += t[id].lazy2 + t[id].lazy1*(m-l+1);
    t[id].lazy1 = t[id].lazy2 = 0;
}
void upd(int id, int l, int r,int u, int v){
    if (u>r||v<l) return;
    if (u<=l&&v>=r){
        t[id].val += (r-l+1)*(r-l+2)/2 + (l-u)*(r-l+1);
        t[id].lazy1 += 1;
        t[id].lazy2 += (l-u);
        return;
    }
    int m = (r+l)/2;
    push(id,l,m,r);
    upd(id*2,l,m,u,v);upd(id*2+1,m+1,r,u,v);
    t[id].val=t[id*2].val+t[id*2+1].val;
}
ll get(int id, int l, int r,int u, int v){
    if (u>r||v<l) return 0;
    if (u<=l&&v>=r){
        return t[id].val;
    }
    int m = (r+l)/2;
    push(id,l,m,r);
    upd(id*2,l,m,u,v);upd(id*2+1,m+1,r,u,v);
    return get(id*2,l,m,u,v) + get(id*2+1,m+1,r,u,v);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    cin >> n >> q;
    f1(i,1,n) cin >> a[i];
    build(1,1,n);
    while (q--){
        cin >> p >> u >> v;
        if (p==1) upd(1,1,n,u,v); else cout << get(1,1,n,u,v) << '\n';
    }

    return 0;
}


