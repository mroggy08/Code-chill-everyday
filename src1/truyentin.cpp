#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
int n,m,u,v,f[N],kq;
vector <int> a[N],ra[N];
stack<int> st;
void dfs1(int u){
    f[u] = 1;
    for (int v : a[u]){
        if (!f[v]){
            dfs1(v);
        }
    }
    st.push(u);
}
void dfs2(int u){
    f[u] = 1;
    for (int v : ra[u]){
        if (!f[v]){
            dfs2(v);
        }
    }
//    st.push(u);
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    while (m--){
        cin >> u >> v;
        a[u].push_back(v);
        ra[v].push_back(u);
    }
    for (int i = 1; i <= n; i++){
        if (!f[i]){
            dfs1(i);
        }
    }
    for (int i = 1; i <= n; i++) f[i]=0;
    while (st.size()){
        int u = st.top();
        st.pop();
//        if (!f[u]){
//            kq++;
//            dfs(u);
//        }
//        cout << u << ' ';
        if (!f[u]){
            dfs2(u);
            cout << u << ' ';
        }
    }
//    cout << kq;


    cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";
    return 0;
}
