#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 2e5+3;
int n,q,a[N],t[N*4],u,v,p;
void build(int id, int l, int r){
    if (l==r){
        t[id]=a[l];
        return;
    }
    int m=(r+l)/2;
    build(id*2,l,m);build(id*2+1,m+1,r);
    t[id]=min(t[id*2],t[id*2+1]);
}
void up(int id, int l, int r, int u, int v){
    if (u<l||u>r) return;
    if (u<=l&&u>=r){
        t[id]=v;
        return;
    }
    int m=(r+l)/2;
    up(id*2,l,m,u,v);up(id*2+1,m+1,r,u,v);
    t[id]=min(t[id*2],t[id*2+1]);
}
int get(int id, int l, int r, int u, int v){
    if (v<l||u>r) return INT_MAX;
    if (u<=l&&v>=r){
        return t[id];
    }
    int m=(r+l)/2;
    return min(get(id*2,l,m,u,v),get(id*2+1,m+1,r,u,v));
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
        if (p==1) up(1,1,n,u,v);
        else cout << get(1,1,n,u,v) << '\n';
    }
    return 0;
}


