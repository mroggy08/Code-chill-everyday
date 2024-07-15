#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pi2 pair<pii,int>
#define vii vector<pii>
#define vi2 vector<pi2>
#define fi first
#define se second
#define pri priority_queue <pii,vii, greater<pii>>
#define pb push_back
#define f1(i, l, r) for (int i = l; i <= r; ++i)
#define f2(i, l, r) for (int i = l; i >= r; --i)
#define f3(i, l, r) for (int i = l; i < r; i++)
#define lb lower_bound
#define ub upper_bound
#define cinarr(a) for (int i = 1; i<=n; ++i) cin >> a[i];
#define cinvec(a) for (auto &x : a) cin >> x;
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define twt int T;cin>>T;while(T--)

const int N = 1e6+3;
const int M = 1e3+3;
const int mod = 1e9+7;
const ll inf = 1e12;

using namespace std;
int n,m,u,v;
vector<int> a[N];
int f[N],par[N];
int Begin=-1, End;
bool dfs(int u)
{
	f[u] = 1;
	for (auto v : a[u])
	{
		if (!f[v])
		{
			par[v] = u;
			dfs(v);
		}
		else  if (f[v]==1)
		{
			Begin = v;
			End = u;
			return 1;
		}
	}
	f[u] = 2;
	return  0;
}
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("INP.INP","r",stdin);
//    freopen("OUT.OUT","w",stdout);
    #endif // ONLINE_JUDGE
    faster;
    cin >> n >> m;
    f1(i,1,m)
    {
    	cin >> u >> v;
    	a[u].pb(v);
    	a[v].pb(u);
    }
    f1(i,1,n) if (dfs(i)) break;
    if (Begin==-1) cout << "IMPOSIBLE";
    else
    {
    	for (int v = End; v != Begin; v=par[v])
    		cout << v << '\n';
    }
    return (0^0);
}
