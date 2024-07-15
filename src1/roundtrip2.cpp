#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
int f[N],rf[N],u,v,n,m,tmp;
vector<set<int>> a;
stack<int> st;
bool dfs(int u){
    f[u]=1;
    st.push(u);
    rf[u]=1;
    for (int v : a[u]){
        if (!f[v]){
            if (dfs(v)) return 1;
        }
        if (rf[v]){
            st.push(v);
            return 1;
        }
    }
    st.pop();
    rf[u]=0;
    return 0;
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    a.resize(n+1);
    while (m--){
        cin >> u >> v;
        a[u].insert(v);
    }
    for (int i = 1; i <= n; i++){
        if (!f[i]){
            if (dfs(i))
                break;
        }
    }
    if (st.empty()){
        cout << "IMPOSSIBLE" << endl;
		return 0;
    }
    vector<int> kq;
    tmp = st.top();;
    while (st.size()){
        int u = st.top();
        st.pop();
        kq.push_back(u);
        if (kq.back()==tmp && kq.size()!=1) break;
    }
    reverse(kq.begin(),kq.end());
    cout << kq.size() << '\n';
    for (int v : kq) cout << v << ' ';

    cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";
    return 0;
}
