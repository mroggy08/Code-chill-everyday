#include <bits/stdc++.h>
#define vi vector<int>
#define vii vector<ii>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)

using namespace std;

const int N = 1e6+3;
const ll inf = 1e18;
const int mo = 1e9+7;
const int dx[4]{1,-1,0,0},dy[4]{0,0,1,-1};
int n,m,u,v,w,f[N],kq;
stack <int> st;
vi a[N],r[N];
void dfs1(int u)
{
    f[u]=1;
    for (int v : a[u])
    {
        if (!f[v])
            dfs1(v);
    }
    st.push(u);
}
void dfs2(int u)
{
    f[u]=1;
    for (int v : r[u])
    {
        if (!f[v])
            dfs2(v);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define task "task"
    if (fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> m;
    while (m--)
    {
        cin >> u >> v;
        a[u].pb(v);
        r[v].pb(u);
    }
    f1(i,1,n) if (!f[i]) dfs1(i);
    f1(i,1,n) f[i]=0;
    while (st.size())
    {
        int u = st.top();
        st.pop();
        if (!f[u])
        {
            kq++;
            dfs2(u);
        }
    }
    cout << kq;
    return 0;
}

