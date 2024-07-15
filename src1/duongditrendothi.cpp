#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define vi vector<int>
#define vii vector<ii>
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
int n,m,s,t,u,v,f[100003],pa[100003],kq[100003];
vector <int> a[100003];
void bfs(){
	f[s]=1;
	queue <int> q;
	q.push(s);
	while (q.size()){
		int u = q.front();
		q.pop();
		for (auto it : a[u]){
			if (!f[it]){
				q.push(it);
				f[it] = 1;
				pa[it] = u;
				if (it==t) return;
			}
		}
	}
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//    #define task "task"
//    if (fopen(task".inp","r")) {
//    	freopen(task".inp","r",stdin);
//    	freopen(task".out","w",stdout);
//    }
    cin >> n >> m >> s >> t;
    while (m--){
    	cin >> u >> v;
    	a[u].pb(v);
    	a[v].pb(u);
    }
    bfs();
    if (f[t]){
//    	cout << pa[t] << ' ' << pa[2];
    	int k = t,d=0;
    	while (k!=s){
            d++;
            kq[d] = k;
            k = pa[k];
    	}
    	d++;
    	kq[d] = s;
    	cout << d << '\n';
    	for (int i = d; i > 0; i--) cout << kq[i] << ' ';
    }
    else {
    	cout << -1;
    }

    return 0;
}
