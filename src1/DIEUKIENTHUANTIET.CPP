#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define Vii vector<ii>
#define fi first
#define se second
#define pri priority_queue <ii,Vii, greater<ii>>
#define pb push_back
#define FOR(i,n) for (int i = 1; i <= (n); i++)
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define twt int T;cin>>T;while(T--)

using namespace std;

const int N = 1e6+3;
const int M = 1e3+3;
const int mod = 1e9+7;
const ll inf = 1e12;
int n,kq,dem[1003],num[1003],low[1003],d,u,v,m;
vector <int> a[1003];
void dfs(int u, int p)
{
	num[u] = low[u] = ++d;
	for (auto v : a[u])
	{
		if (v==p) continue;
		if (num[v]) low[u] = min(low[u],num[v]);
		else {
			dfs(v,u);
			dem[u] += dem[v];
			low[u] = min(low[u],low[v]);
			if (low[v]>num[u]) kq += dem[v]*(n-dem[v]);
		}
	}
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("INP.INP","r",stdin);
    freopen("OUT.OUT","w",stdout);
    #endif // ONLINE_JUDGE
    faster;
    cin >> n >> m;
    FOR(i,m) {
    	cin >> u >> v;
    	a[u].pb(v);
    	a[v].pb(u);
    }
    FOR(i,n) dem[i] = 1;
    dfs(1,0);
    cout << kq;
    return (0^0);
}