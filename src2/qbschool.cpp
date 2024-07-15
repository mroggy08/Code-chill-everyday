#include <bits/stdc++.h>
#define f1(i,n,m) for (int i=n; i<=m; i++)
#define file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }
#define ll long long
#define ii pair<ll,int>
#define vii vector<ii>
#define fi first
#define se second
using namespace std;

const int N = 5e3+5;
int n,m,k,u,v;
vii a[N];
ll d[N],sz[N],w;
void Dij(){
	f1(i,2,n) d[i]=1e18;
	sz[1]=1;
	priority_queue <ii, vii, greater<ii>> q;
	q.push({0,1});
	while (q.size()){
		ll du = q.top().fi; int u = q.top().se; q.pop();
		if (du>d[u]) continue;
		for (ii e : a[u]){
			ll dv = e.fi; int v = e.se;
			if (d[v]>du+dv){
				d[v]=du+dv;
				q.push({d[v],v});
				sz[v] = sz[u];
			} else if (d[v]==du+dv) sz[v]+=sz[u];
		}
	}
	cout << d[n] << ' ' << sz[n];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	file("1");
	cin >> n >> m;
	while (m--){
		cin >> k >> u >> v >> w;
		a[u].push_back({w,v});
		if (k==2) a[v].push_back({w,u});
	}
	Dij();
	// cout << d[n];
    return 0;
}



