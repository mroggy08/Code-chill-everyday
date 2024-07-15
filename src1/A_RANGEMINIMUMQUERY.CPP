#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define f1(i,n,m) for (int i = n; i <= m; i++)
#define fz(i,n) for (int i = 0; i < n; i++)
#define __ThanhDat int main
using namespace std;
const int N = 1e5+3;
const ll mo = 1000000007;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int n,q,a[N],t[4*N],u,v;
void build(int id, int l, int r)
{
	if (l==r) {
		t[id] = a[l];
		return;
	}
	int m = (r+l)/2;
	build(id*2,l,m);
	build(id*2+1,m+1,r);
	t[id] = min(t[id*2],t[id*2+1]);
}
int get(int id, int l, int r,int u, int v)
{
	if (u>r||v<l) return INFINITY;
	if (u <= l && v>=r) return t[id];
	int m = (r+l)/2;
	return min(get(id*2,l,m,u,v),get(id*2+1,m+1,r,u,v));
}
__ThanhDat()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    #define task "inp"
    if (fopen(task".inp","r")) {
    	freopen(task".inp","r",stdin);
    	freopen(task".out","w",stdout);
    }
    cin >> n >> q;
    f1(i,1,n) cin >> a[i];
    build(1,1,n);
    while (q--)
    {
    	cin >> u >> v;
    	// for (int i = u; i <= v; i++) cout << a[i] << ' ';
    	// 	cout << '\n';
    	cout << get(1,1,n,u,v) << '\n';
    }


    return 0;
}
