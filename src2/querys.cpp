#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, a, b) for(int i = a, _n = b; i <= _n; ++i)
const int N = 2e5+5;

int n, m, q, a[N];

struct SegmentTree {
    int val[N<<2], lazy[N<<2];
    void build(int id, int l, int r){
        if (l == r) {
        val[id] = a[l] % m;
        return;
        }
        int mid = (l + r) >> 1;
        build(id<<1, l, mid);
        build(id<<1|1, mid+1, r);
        val[id] = (val[id<<1] + val[id<<1|1]) % m;
    }
    void down(int id, int l, int r){
        if (lazy[id]) {
            int mid = (l + r) >> 1;
            val[id<<1] = (val[id<<1] + 1LL * lazy[id] * (mid - l + 1)) % m;
            val[id<<1|1] = (val[id<<1|1] + 1LL * lazy[id] * (r - mid)) % m;
            lazy[id<<1] = (lazy[id<<1] + lazy[id]) % m;
            lazy[id<<1|1] = (lazy[id<<1|1] + lazy[id]) % m;
            lazy[id] = 0;
        }
    }
    void update(int id, int l, int r, int u, int v, int x){
        if (l > v || r < u) return;
        if (l >= u && r <= v) {
            val[id] = (val[id] + 1LL * x * (r - l + 1)) % m;
            lazy[id] = (lazy[id] + x) % m;
//            cout << val[id] << ' ' << lazy[id] << ' ';
            return;
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        update(id<<1, l, mid, u, v, x);
        update(id<<1|1, mid+1, r, u, v, x);
//        cout << val[id*2] << ' ' << val[id*2+1] << ' ';
        val[id] = (val[id<<1] + val[id<<1|1]) % m;
    }
    int get(int id, int l, int r, int u, int v) {
        if (l > v || r < u) return 0;
        if (l >= u && r <= v) return val[id];
        down(id, l, r);
        int mid = (l + r) >> 1;
        return (get(id<<1, l, mid, u, v) + get(id<<1|1, mid+1, r, u, v)) % m;
    }
}st;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("1.inp","r",stdin);
    freopen("1.ans","w",stdout);
    cin>>m>>n>>q;
    FOR(i, 1, n) cin >> a[i];
    st.build(1, 1, n);
//    FOR(i,1,4*n) cout << st.val[i] << ' ';
//    cout << '\n';
    while (q--) {
        int tp, u, v, x;
        cin>>tp;
        if (tp == 1) {
            cin >> u >> v >> x;
            st.update(1, 1, n, u, v, x);
//            FOR(i,1,4*n) cout << st.val[i] << ' ';
//            cout << '\n';
//            cout << '\n';

        }else{
            cin >> u >> v;
            for (int i = 1; i <= 4*n; i++) cout << st.val[i] << ' ';
            cout << '\n';
            cout << st.get(1, 1, n, u, v) << '\n';
        }
    }return 0;
}
