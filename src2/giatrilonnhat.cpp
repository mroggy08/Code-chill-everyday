#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 5e4+3;
struct sv{
    ll lz,gt;
};
sv t[N*4];
int n,m,p,u,v;
ll vx;
void push(int id){
    if (t[id].lz){
        t[id*2+1].gt += t[id].lz;
        t[id*2].gt += t[id].lz;
        t[id*2].lz += t[id].lz;
        t[id*2+1].lz += t[id].lz;
        t[id].lz = 0;
    }
}
void up(int id, int l, int r, int u, int v, ll vx){
    if (u>r||v<l) return;
    if (u<=l&&v>=r){
        t[id].lz+=vx;
        t[id].gt+=vx;
        return;
    }
    int m=(r+l)/2;
    push(id);
    up(id*2,l,m,u,v,vx);up(id*2+1,m+1,r,u,v,vx);
    t[id].gt=max(t[id*2].gt,t[id*2+1].gt);
}
ll get(int id, int l, int r, int u, int v){
    if (u>r||v<l) return 0;
    if (u<=l&&v>=r){
        return t[id].gt;
    }
    int m=(r+l)/2;
    push(id);
    return max(get(id*2,l,m,u,v),get(id*2+1,m+1,r,u,v));
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    cin >> n >> m;
    while (m--){
        cin >> p >> u >> v;
        if (!p) {
            cin >> vx;
            up(1,1,n,u,v,vx);
        } else cout << get(1,1,n,u,v) << '\n';
    }

    return 0;
}

