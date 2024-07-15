// OwO mãi simp tnqa >~< UwU
//#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#include <bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define ul unsigned long long
#define pb push_back
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define repp(i, a, b) for (int i = a; i >= b; --i)
#define TEST "TEST"

const ll maxn = 2e5 + 2;
//const ll oo = 1e18;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const ll mod[] = {(ll) 1e9 + 7, (ll)1e9 + 2277, (ll)1e9 + 5277, (ll)1e9 + 8277, (ll)1e9+ 9277};
const ll MOD = 1e9 + 7;
const int LOG = 20;
//const ll base = 71;

using namespace std;

inline int readInt(){char c;while(c=getchar(),c!='-'&&(c<'0'||c>'9'));bool sign=(c=='-');if(sign)c=getchar();int n=c-'0';while(c=getchar(),c>='0'&&c<='9')n=10*n+c-'0';return(!sign)?n:-n;}
inline ll readLong(){char c;while(c=getchar(),c!='-'&&(c<'0'||c>'9'));bool sign=(c=='-');if(sign)c=getchar();ll  n=c-'0';while(c=getchar(),c>='0'&&c<='9')n=10*n+c-'0';return(!sign)?n:-n;}
inline ul readUL(){char c;while(c=getchar(),c!='-'&&(c<'0'||c>'9'));bool sign=(c=='-');if(sign)c=getchar();ll  n=c-'0';while(c=getchar(),c>='0'&&c<='9')n=10*n+c-'0';return(!sign)?n:-n;}
inline string readString() {char c;while(c=getchar(),c==' '||c=='\n'||c=='\t');string s({c});while(c=getchar(),c!=EOF&&c!=' '&&c!='\n'&&c!='\t')s+=c;return s;}

int n, q, h[maxn], st[maxn][21];
ll f[maxn];
vector<pair<int, ll>> a[maxn];

void dfs(int u){
    for (auto i : a[u]){
        int v = i.f; ll w = i.s;
        if (v == st[u][0]) continue;
        h[v] = h[u] + 1;
        f[v] = f[u] + w;
        st[v][0] = u;
        rep(j, 1, LOG){
            st[v][j] = st[st[v][j - 1]][j - 1];
        }
        dfs(v);
    }
}

int ntt(int u, int k){
    for (int j = 0; (1 << j) <= k; ++j)
        if (k >> j & 1) u = st[u][j];
    return u;
}

int lca(int u, int v){
    if (h[u] != h[v]){
        if (h[u] < h[v]) swap(u, v);
        u = ntt(u, h[u] - h[v]);
    }
    if (u == v) return u;
    repp(j, __lg(h[u]), 0){
        if (st[u][j] != st[v][j]){
            u = st[u][j];
            v = st[v][j];
        }
    }
    return st[u][0];
}

ll dt(int u, int v){
    cout << u << ' ' << v << '\n';
    cout << f[u] << ' ' << f[v] << ' ' << lca(u,v) << ' ' << f[lca(u,v)] << ' ';
    return f[u] + f[v] - (2 * f[lca(u, v)]);
}

void sol(){
    n = readInt();
    rep(i, 1, n - 1){
        int u, v; ll w;
        u = readInt(); v = readInt(); w = readLong();
        a[u].pb({v, w});
        a[v].pb({u, w});
    }
    dfs(1);
    q = readInt();
    while (q--){
        int b, c, d;
        b = readInt(); c = readInt(); d = readInt();
                cout <<  dt(c,lca(b,d)) << '\n';
//        cout << dt(b, lca(b, d)) << ' ' << dt(c, lca(b, d)) << ' ' << dt(d, lca(b, d)) << '\n';
//        cout << lca(b,d) << ' ' << dt(c,lca(b,d)) << '\n';
//        cout << dt(b, lca(b, c)) + dt(c, lca(b, c)) + dt(d, lca(b, c)) << ' ';
//        cout << dt(b, lca(b, d)) + dt(c, lca(b, d)) + dt(d, lca(b, d)) << ' ';
//        cout << dt(b, lca(c, d)) + dt(c, lca(c, d)) + dt(d, lca(c, d)) << ' ';
//        cout << min({dt(b, lca(b, c)) + dt(c, lca(b, c)) + dt(d, lca(b, c)),
//                     dt(b, lca(b, d)) + dt(c, lca(b, d)) + dt(d, lca(b, d)),
//                     dt(b, lca(c, d)) + dt(c, lca(c, d)) + dt(d, lca(c, d))}) << "\n";
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
   if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    int t; t = 1;
    while(t--){
        sol();
        cout << "\n";
    }
    return 0;
}
