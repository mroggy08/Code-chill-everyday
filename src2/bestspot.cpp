#include <bits/stdc++.h>
#define f1(i,n,m) for (int i=n; i<=m; i++)
#define file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }
#define ll long long
#define ii pair<ll,int>
#define vii vector<ii>
#define fi first
#define se second
using namespace std;

const int N = 5e2+5;
int P,n,C,ai,u,v;
ll w,d[N][N];
vector<int> fav;
vii a[N];
void Dij(int s){
	priority_queue <ii, vii, greater<ii>> q;
	f1(i,1,P) d[s][i] = 1e18;
	d[s][s] = 0;
	q.push({0,s});
	while (q.size()){
		ll du = q.top().fi; int u = q.top().se; q.pop();
		if (du>d[s][u]) continue;
		for (ii e : a[u]){
			ll dv = e.fi; int v = e.se;
			if (d[s][v]>du+dv){
				d[s][v]=du+dv;
				q.push({d[s][v],v});	
			} 
		}
	}
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	file("1");
	cin >> P >> n >> C;
	while (n--){
		cin >> ai;
		fav.push_back(ai);
	}
	while (C--){
		cin >> u >> v >> w;
		a[u].push_back({w,v});
		a[v].push_back({w,u});
	}
	for (int v : fav) Dij(v);
	int ans = 1;
	ll res, ret = LLONG_MAX;
	f1(i,1,P){
		res = 0;
		for (int v : fav){
			res += d[v][i];
		}
		if (res < ret){
			ret = res;
			ans = i;
		}
	}
	cout << ans;
    return 0;
}



