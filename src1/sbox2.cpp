#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 1e5+5;
int n,q,ty,u,v,w;
struct sv{
    ll val;
    int lazy;
};
sv t[N*4];
void push(int id, int l, int r,int m){
    if (t[id].lazy!=0){
        t[id*2].val += t[id].lazy*(m-l+1);
        t[id*2+1].val += t[id].lazy*(r-m);
        t[id*2].lazy += t[id].lazy;
        t[id*2+1].lazy += t[id].lazy;
        t[id].lazy = 0;
    }
}
void up(int id, int l, int r, int u, int v, int w){
    if (u>r||v<l) return;
    if (u<=l&&v>=r){
        t[id].val += w*(r-l+1);
        t[id].lazy += w;
        return;
    }
    int m = (r+l)/2;
    push(id,l,r,m);
    up(id*2,l,m,u,v,w);
    up(id*2+1,m+1,r,u,v,w);
    t[id].val = t[id*2].val+t[id*2+1].val;
}
ll get(int id, int l, int r, int u, int v){
    if (u>r||v<l) return 0;
    if (u<=l&&v>=r) return t[id].val;
    int m = (r+l)/2;
    push(id,l,r,m);
    return get(id*2,l,m,u,v)+get(id*2+1,m+1,r,u,v);
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    while (q--){
        cin >> ty;
        if (ty==1){
            cin >> u >> v >> w;
            up(1,1,n,u,v,w);
        }
        else {
            cin >> u;
            cout << get(1,1,n,u,u) << '\n';
        }
    }
    return 0;
}
