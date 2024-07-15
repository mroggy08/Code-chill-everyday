#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+9;
struct sv{
    int mi,ma;
};
sv t[N*4];
ll S1,S2,s[N];
int n,q,u,v,a[N],mi,ma;
void build(int id, int l, int r){
    if (l==r){
        t[id].mi = a[l];
        t[id].ma = a[l];
        return;
    }
    int mid = (r+l)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    t[id].mi = min(t[id*2].mi,t[id*2+1].mi);
    t[id].ma = max(t[id*2].ma,t[id*2+1].ma);
}
int getmin(int id, int l, int r, int u, int v){
    if (u>r||v<l) return INT_MAX;
    if (u<=l && v>=r) return t[id].mi;
    int mid = (r+l)/2;
    return min(getmin(id*2,l,mid,u,v),getmin(id*2+1,mid+1,r,u,v));
}
int getmax(int id, int l, int r, int u, int v){
    if (u>r||v<l) return INT_MIN;
    if (u<=l && v>=r) return t[id].ma;
    int mid = (r+l)/2;
    return max(getmax(id*2,l,mid,u,v),getmax(id*2+1,mid+1,r,u,v));
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i],s[i]=s[i-1]+a[i];
    build(1,1,n);
    while (q--){
        cin >> u >> v;
        mi = getmin(1,1,n,u,v);
        ma = getmax(1,1,n,u,v);
        if (mi == ma) {
            cout << "NO\n";
            continue;
        }
        ll S = (mi+ma)*(v-u+1);
        if (S&1) S1 = S/2+1;
        else S1 = S/2;
        S2 = s[v] - s[u-1];
//        cout << S1 << ' ' << S2 << '\n';
        cout << (S1==S2 ? "YES" : "NO") << '\n';
    }
    cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";
    return 0;
}
