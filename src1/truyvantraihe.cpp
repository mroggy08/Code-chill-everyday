#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
int n,q,u,v;
char ch;
ll t[N*4];
void up(int id, int l, int r, int u, int v){
    if (u>r||u<l) return;
    if (u<=l&&u>=r){
        t[id] = v;
        return;
    }
    int m = (r+l)/2;
    up(id*2,l,m,u,v);
    up(id*2+1,m+1,r,u,v);
    t[id] = t[id*2] + t[id*2+1];
}
ll get(int id, int l, int r, int u, int v){
    if (u>r||v<l) return 0;
    if (u<=l&&v>=r) return t[id];
    int m = (r+l)/2;
    return get(id*2,l,m,u,v) + get(id*2+1,m+1,r,u,v);
}
int main()
{
    if(fopen("QUERYSUM.inp","r")){freopen("QUERYSUM.inp","r",stdin);freopen("QUERYSUM.out","w",stdout);}
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    while (q--){
        cin >> ch >> u >> v;
        if (ch=='S') up(1,1,n,u,v);
        else cout << get(1,1,n,u,v) << '\n';
    }


    cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";
    return 0;
}
