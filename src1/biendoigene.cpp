#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define vi2 vector<ii>
#define X first
#define Y second
#define pri priority_queue <ii,Vii, greater<ii>>
#define pb push_back
#define f1(i,n,m) for (int i=(n);i<=(m);++i)
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;

const int N = 2e5+3;
const ll mod = 1e3+7;
int n,q,tc,u,v; ll k;
ll f[2][2], M[2][2],t[N*4],lazy[N*4];
void cal(ll f[2][2], ll M[2][2])
{
	ll x,y,z,t;
    x = (f[0][0]*M[0][0]%mod + f[0][1]*M[1][0]%mod)%mod;
    y = (f[0][0]*M[0][1]%mod + f[0][1]*M[1][1]%mod)%mod;
    z = (f[1][0]*M[0][0]%mod + f[1][1]*M[1][0]%mod)%mod;
    t = (f[1][0]*M[0][1]%mod + f[1][1]*M[1][1]%mod)%mod;
    f[0][0] =x;f[0][1]=y;f[1][0]=z;f[1][1]=t;
}
void lt(ll f[2][2], ll m)
{
	if (m<=1) return ;
	lt(f,m/2);
	cal(f,f);
	if (m&1) cal(f,M);
}
ll matrix(ll m)
{
	f[0][0] = f[0][1] = f[1][0] = 1; f[1][1] = 0;
	M[0][0] = M[0][1] = M[1][0] = 1; M[1][1] = 0;
	if (m==0) return 0;
	lt(f,m-1);
	return f[0][0];
}
void push(int id, int l, int mid, int r)
{
	if (lazy[id])
	{
		t[id<<2] += lazy[id]*(mid-l+1);
		t[id<<2+1] += lazy[id]*(r-mid);
		lazy[id<<2] += lazy[id];
		lazy[id<<2+1] += lazy[id];
		lazy[id]=0;
	}
}
void up(int id, int l, int r, int u, int v, ll val)
{
	if (u>r||v<l) return;
	if (u<=l&&v>=r) 
	{
		t[id]+=val*(r-l+1);
		lazy[id]+=val;
		return;
	}
	int mid = (r+l)>>1;
	push(id,l,mid,r);
	up(id<<2,l,mid,u,v,val); up(id<<2|1,mid+1,r,u,v,val); t[id] = t[id<<2] + t[id<<2+1];
}
ll get(int id, int l, int r, int u, int v)
{
	if (u>r||v<l) return 0;
	if (u<=l&&v>=r) 
		return t[id];
	int mid = (r+l)>>1;
	push(id,l,mid,r);
	return get(id<<2,l,mid,u,v) + get(id<<2+1,mid+1,r,u,v);
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("TASK.INP","r",stdin);
    freopen("TASK.OUT","w",stdout);
    fastIO;
    #endif // ONLINE_JUDGE
    cin >> n >> q;
    while (q--)
    {
    	cin >> tc >> u >> v;
    	if (tc==1) 
    	{
    		cin >> k, up(1,1,n,u,v,matrix(k));
    		// cout << matrix(k) << '\n';
    	}
    	else cout << get(1,1,n,u,v) << '\n';
    }
    return (0^0);
}
