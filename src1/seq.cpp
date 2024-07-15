#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
using namespace std;

const int maxn = 1e5+5;
const int N = 2e9;
int n,q,k;
ii a[maxn];
int L[maxn],R[maxn];
void work()
{
	stack <int> st;
	a[0].fi = a[n+1].fi = N;
	st.push(0);
	for (int i = 1; i <= n; i++)
	{
		int x = a[i].fi;
		while (a[st.top()].fi >= x) st.pop();
		L[i] = st.top() + 1;
		st.push(i);
	}
	while (st.size()) st.pop();
	st.push(n+1);
	for (int i = n; i > 0; i--)
	{
		int x = a[i].fi;
		while (a[st.top()].fi >= x) st.pop();
		R[i] = st.top() - 1;
		st.push(i);
	}
	for (int i = 1; i <= n; i++)
		a[i].se = R[i] - L[i] + 1;
}
bool cmd(ii X, ii Y)
{
	if (X.fi==Y.fi) return X.se < Y.se;
	return X.fi < Y.fi;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("INP.INP","r",stdin);
    // freopen("OUT.OUT","w",stdou;t)
    #endif // ONLINE_JUDGE
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i].fi;
    work();
	sort(a+1,a+n+1,cmd);
	for (int i = 2; i <= n; i++)
		a[i].se = max(a[i].se,a[i-1].se);
	for (int i = 1; i <= q; i++)
	{
		cin >> k;
		ii x = {k,N};
		int vt = upper_bound(a+1,a+n+1,x) - a - 1;
		cout << a[vt].se << '\n';
	}
    return 0;
}