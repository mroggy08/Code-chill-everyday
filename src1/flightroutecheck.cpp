#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,sse4,avx,avx2,fma,bmi,bmi2,abm")
#include<bits/stdc++.h>
#define TrThanhDat int main()
#define ii pair<int,int>
#define fi first
#define se second
#define f1(i,n,m) for(int i=n;i<=m;i++)
#define f2(i,n,m,j) for (int i=n;i>=m;i-=j)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lb;
void fan_manchesterunited_20nam() {ios_base::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);}
void times() {cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";}
ll gcd(ll a, ll b) {return __gcd(a,b);}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}
const ll mod = 1e9+7;
const int N = 2e5+3;
int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
char duong[] = {'R', 'L', 'D', 'U'};
const ll inf = 1e20;
int f[N],n,m,u,v,cmp,bd,kt,h[N];
stack <int> st;
vector <int> a[N],ra[N];
void dfs1(int s)
{
    f[s] = 1;
    for (int v : a[s])
    {
        if (!f[v])
        {
            dfs1(v);
        }
    }
    st.push(s);
}
void dfs2(int s)
{
    f[s] = 1;
    for (int v : ra[s])
    {
        if (!f[v])
        {
            dfs2(v);
        }
    }
//    st.push(s);
}
void dfs3(int s)
{
    h[s] = 1;
    for (int v : a[s])
    {
        if (!h[v])
            dfs3(v);
    }
}
TrThanhDat {
    fan_manchesterunited_20nam;
    #define name "task"
    if(fopen(name".inp","r")){freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
    cin >> n >> m;
    while (m--)
    {
        cin >> u >> v;
        a[u].push_back(v);
        ra[v].push_back(u);
    }
    f1(i,1,n) if (!f[i]) dfs1(i);
    f1(i,1,n) f[i]=0;
    while (st.size())
    {
        int u = st.top();
//        cout << u << ' ';
        st.pop();
        if (!f[u])
        {
            cmp++;
            if (cmp==1) bd=u;
            if (cmp==2) kt=u;
            dfs2(u);
        }
    }
    if (cmp==1)
    {
        cout << "YES";
    } else {
        cout << "NO\n";
//        cout << bd << ' ' << kt;
        dfs3(bd);
        if (h[kt]==1) cout << kt << ' ' << bd;
        else cout << bd << ' ' << kt;
    }
    times();
    return (0 ^ 0);
}
