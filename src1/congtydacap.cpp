#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 1e5+5;
int n,m,u,v,f[N],kq;
stack <int> st;
vector<int> a[N],ra[N];
void dfs(int u){
    f[u]=1;
    for (int v : a[u]){
        if (!f[v])
            dfs(v);
    }
    st.push(u);
}
void scc(int u){
    f[u]=1;
    for (int v : ra[u]){
        if (!f[v])
            scc(v);
    }
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        a[u].pb(v);
        ra[v].pb(u);
    }
    for (int i = 1; i <= n; i++) if (!f[i]) dfs(i);
    for (int i = 1; i <= n; i++) f[i]=0;
    while (st.size()){
//        if (f[st.top()]==0) scc(st.top()),kq++;
//        st.pop();
        int h = st.top();
        st.pop();
        if (!f[h]) scc(h),kq++;
    }
    cout << kq;
    return 0;
}
