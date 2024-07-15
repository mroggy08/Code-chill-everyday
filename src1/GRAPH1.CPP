
#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define Vii vector<ii>
#define fi first
#define se second
#define pri priority_queue <ii,Vii, greater<ii>>
#define pb push_back
#define f1(i,n,m) for (int i = (n); i <= (m); i++)
#define f2(i,n,m) for (int i = (n); i < (m); i++)
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define twt int T;cin>>T;while(T--)

using namespace std;

const int mod = 1e9+7;
const ll inf = 1e12;
int n,m,u,v,vis[20003],kq[20003],num[20003],low[20003],tplt,d;
vector <int> a[50003];
void dfs(int u)
{
    vis[u] = 1;
    for (int v : a[u])
        if (!vis[v]) dfs(v);
}
void tj(int u, int p)
{
    num[u] = low[u] = ++d;
    int c = 0;
    for (int v : a[u])
    {
        if (v==p) continue;
        if (num[v]) low[u] = min(low[u],num[v]);
        else {
            tj(v,u);
            low[u] = min(low[u],low[v]);
            c++;
//            if (low[v]==num[v]) cau++;
            if (!p)
            {
                if (c>1) kq[u]++;
            }
            else if (low[v]>=num[u]) kq[u]++;
        }
    }
}
int main()
{
//     freopen("INP.INP","r",stdin);
//     freopen("OUT.OUT","w",stdout);
    faster;
    cin >> n >> m;
    f1(i,1,m) {
    	cin >> u >> v;
    	a[u].pb(v);
    	a[v].pb(u);
    }
    f1(i,1,n) if (!vis[i]) dfs(i),tplt++;
    f1(i,1,n) if (!num[i]) tj(i,0);
//    cout << cau << '\n';
    f1(i,1,n)
    {
        if (!a[i].size()) cout << tplt - 1 << '\n';
        else cout << kq[i] + tplt << '\n';
//        cout << kq[i] << '\n';
    }
    return (0^0);
}
