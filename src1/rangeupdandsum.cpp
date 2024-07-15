#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define vi vector<int>
#define vii vector<ii>
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
#define bit(i1,x) ((x>>i)&1)
#define bp __builtin_popcount
#define inf INT_MAX
using namespace std;
const int N = 2e5+3;
struct sv{
    ll val,lazy;
};
sv t[N*4];
int n,q,u,v,ty,w,a[N];
void build(int id, int l, int r)
{
	if (l==r){
		t[id].val = a[l];
		// t[id].val2 = a[l];
 		return;
	}
	int mid = (r+l)>>1;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	t[id].val = t[id*2].val + t[id*2+1].val;
	// t[id].val1 = t[id*2].val1 + t[id*2+1].val1;
}
void push1(int id, int l, int r, int mid)
{
    if (t[id].lazy)
    {
        t[id*2].val += t[id].lazy*(mid-l+1);
        t[id*2+1].val += t[id].lazy*(r-mid);
        t[id*2].lazy += t[id].lazy;
        t[id*2+1].lazy += t[id].lazy;
        t[id].lazy = 0;
    }
}
void push2(int id, int l, int r, int mid)
{
    if (t[id].lazy)
    {
        t[id*2].val = t[id].lazy*(mid-l+1);
        t[id*2+1].val = t[id].lazy*(r-mid);
        t[id*2].lazy = t[id].lazy;
        t[id*2+1].lazy = t[id].lazy;
        t[id].lazy = 0;
    }
}
void upd(int th,int id, int l, int r, int u, int v, int val)
{
	if (u > r|| v < l) return;
	if (u<=l && v>=r)
	{
		if (th==1)
		{
			t[id].val += val*(r-l+1);
			t[id].lazy += val;
		} else {
			t[id].val = val*(r-l+1);
			t[id].lazy = val;
		}

	}
	int mid = (r+l)>>1;
//	push1(id,l,r,mid);
	push2(id,l,r,mid);
	upd(th,id*2,l,mid,u,v,val);
	upd(th,id*2+1,mid+1,r,u,v,val);
	t[id].val = t[id*2].val + t[id*2+1].val;
	// t[id].val1 = t[id*2].val1 + t[id*2+1].val1;
}
// void upd1(int id, int l, int r, int u, int v, int val)
// {
// 	if (u > r|| v < l) return;
// 	if (u<=l && v>=r)
// 	{
// 		t[id].val = val;
// 		t[id].lazy1 = val;

// 	}
// 	int mid = (r+l)>>1;
// 	push(id,l,r,mid);
// 	upd1(id*2,l,mid,u,v,val);
// 	upd1(id*2+1,mid+1,r,u,v,val);
// 	t[id].val= t[id*2].val + t[id*2+1].val;

// }
ll get(int id, int l, int r, int u, int v)
{
	if (u > r|| v < l) return 0;
	if (u<=l && v>=r)
	{
		return t[id].val;

	}
	int mid = (r+l)>>1;
//	push1(id,l,r,mid);
	push2(id,l,r,mid);
	// upd1(id*2,l,mid,u,v,val);
	// upd1(id*2+1,mid+1,r,u,v,val);
	// t[id].val1 = t[id*2].val1 + t[id*2+1].val1;
	// t[id].val1 = t[id*2].val1 + t[id*2+1].val1;
	return get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define task "task"
    if (fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> q;
    f1(i,1,n) cin >> a[i];
    build(1,1,n);
    while (q--)
    	{
    		cin >> ty;
    		if (ty==1)
    		{
    			cin >> u >> v >> w;
    			upd(1,1,1,n,u,v,w);
    		} else
    		if (ty==2)
    		{
    			cin >> u >> v >> w;
    			upd(2,1,1,n,u,v,w);
    		} else
    		{
    			cin >> u >> v;
    			cout << get(1,1,n,u,v) << '\n';
    		}
    	}
    for (int i = 1;i <= 4*n; i++)
        cout << t[i].val << ' ';
    return 0;
}
