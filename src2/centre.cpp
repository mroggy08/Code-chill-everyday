#include <bits/stdc++.h>
#define f1(i,n,m) for (int i=n; i<=m; i++)
#define file(name)  if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }
#define ll long long
#define fi first
#define se second
#define ii pair<int,int>
using namespace std;

const int N = 3e5+5;
const int INF=1e9;
int n,m,ret;
vector<ii> a[N];
vector<int> d1,dn,s1,sn;
void Dij(int s, vector<int> &d, vector<int> &sz){
	d.resize(n+1,INF);
	sz.resize(n+1,0);
	d[s]=0; sz[s]= 1;
	priority_queue <ii, vector<ii>, greater<ii>> q;
	q.push({0,s});
	while (q.size()){
		int du = q.top().fi, u = q.top().se; q.pop();
		if (du>d[u]) continue;
		for (ii e : a[u]){
			if (d[e.se]==e.fi+du) sz[e.se] += sz[u];
			if (d[e.se] > e.fi + du){
				d[e.se] = e.fi + du;
				sz[e.se] = sz[u];
				q.push({d[e.se],e.se});
			}
		}
	}
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	file("1");
	cin >> n >> m;
	while (m--){
		int u,v, w;
		cin >> u >> v >> w;
		a[u].push_back({w,v});
		a[v].push_back({w,u});
	}
	Dij(1,d1,s1);
	Dij(n,dn,sn);
	 vector<int> ans;
    for (int i=2;i < n;i++) {
        // if (d1[i] + dn[i] > d1[n]) {
        //     ans.pb(i);
        // }
        // else if (w1[i] * wn[i] < w1[n])
        //     ans.pb(i);
        if (!(d1[i] + dn[i] == d1[n] && s1[i] * sn[i] == s1[n])) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for (auto i : ans) {
        cout << i << endl;
    }
    return 0;
}



