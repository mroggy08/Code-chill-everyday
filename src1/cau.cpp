#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define vi2 vector<ii>
#define X first
#define Y second
#define pri priority_queue <ii,Vii, greater<ii>>
#define pb push_back
#define f1(i,n,m) for (int i=(n);i<=(m);++i)
#define fastIO ios_base::sync_with_stdio(0)
using namespace std;

const int N = 1e6+3;

int n,m,u,v,low[N],num[N],cnt,cau;
vector <int> a[N];
vector <int> khop;
vector <ii> Cau;
bool ok[N];
void dfs(int u, int p)
{
    int child=0;
    num[u] = low[u] = ++cnt;
    for (auto v : a[u])
    {
        if (v==p) continue;
        if (num[v]) low[u] = min(low[u], num[v]);
        else {
            dfs(v,u);
            low[u] = min(low[u],low[v]);
            if (low[v]==num[v]) {
            	cau++;
            	Cau.pb({v,u});
            }
            child++;
            if (u==p) {
               if (child>1) {
               	ok[u] = 1;
               	if (find(khop.begin(),khop.end(),u)==khop.end()) khop.pb(u);
               }
               
            }
            else if (low[v]>=num[u]) {
            	ok[u] = 1;
            	if (find(khop.begin(),khop.end(),u)==khop.end()) khop.pb(u);
            }
        }
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("TASK.INP","r",stdin);
    freopen("TASK.OUT","w",stdout);
    fastIO;
    #endif // ONLINE_JUDGE
    cin >> n >> m;
    while (m--)
    {
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
    
    f1(i,1,n) if (!num[i]) dfs(i,i);
    // f1(i,1,n) if (ok[i]) khop.pb(i);

    cout << khop.size() << ' ' << cau << '\n';
    // sort(khop.begin(),khop.end());
    for (auto t : khop) cout << t << '\n';
    // cout << '\n';
	for (auto it : Cau) cout << it.Y << ' ' << it.X << '\n';
    return 0;
}
