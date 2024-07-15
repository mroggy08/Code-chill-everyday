#include <bits/stdc++.h>
#define f1(i,n,m) for (int i=n; i<=m; i++)
#define fd(i,n) for (int i=n;i>=1; i--)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define ii pair<int,int>
#define lli pair<ll,int>
#define VI vector<int>
#define VII vector<ii>
#define VLLI vector<lli>
#define ALL(a) a.begin(),a.end()
using namespace std;
//const int N = 3e4+5;
const int M = 1e6+6;
const int maxN = 3e4+5;
int n,a[maxN],q,l,vt[M],nxt[maxN],r,bit[maxN],ans[maxN];
vector<ii> query[maxN];
void upd(int i){
    for (; i<=n ; i += i & -i) bit[i]++;
}
int getsum(int i){
    int res = 0;
    for (;i>0;i -= i&-i) res+=bit[i];
    return res;
}
int sum(int l, int r){
//    cout << getsum(r) << ' ' << getsum(l-1) << '\n';
    return getsum(r) - getsum(l-1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    f1(i,1,n) cin >> a[i];
    fd(i,n){
        if (!vt[a[i]]) upd(i);
        else nxt[vt[a[i]]] = i;
        vt[a[i]] = i;
    }
    cin >> q;
    f1(i,1,q){
        cin >> l >> r;
        query[r].pb({l,i});
    }
    fd(r,n){
        for (ii e : query[r]){
            int L = e.fi, idx = e.se;
            ans[idx] = sum(L,r);
        }
        if (nxt[r]) upd(nxt[r]);
    }
    f1(i,1,q) cout << ans[i] << '\n';
    return 0;
}
