#include <bits/stdc++.h>
#define file(name) if(fopen(name".inp","r")){freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define f1(i,n,m) for (int i = n; i <= m; i++)
#define fd(i,n) for (int i = n; i > 0; i--)
#define ii pair<int,int>
#define lli pair<ll,int>
#define fi first 
#define se second
#define pb push_back
#define ll long long 
#define VI vector<int>
#define VII vector<ii>
#define lb lower_bound
#define ub upper_bound
#define VLLI vector<lli>
#define ALL(a) a.begin(),a.end()
using namespace std;
const int N = 1e5+5;
const int oo = 1e9+7;
int n,q,a[N],u,v,val,k;
int t[N*4];
void upd(int id, int l, int r, int pos, int val){
	if (pos<l||pos>r) return;
	if (l==r){
		t[id] = val;
		return;
 	}
 	int m = (r+l)>>1;
 	upd(id*2,l,m,pos,val);upd(id*2+1,m+1,r,pos,val);
 	t[id]=min(t[id*2],t[id*2+1]);
}
int get(int id, int l, int r, int u, int v, int val){
	if (u>r||v<l) return -1;
	if (l==r)	return l;
	int m = (r+l)/2;
	int res = -1;
	if (t[id*2]<=val){
		res = get(id*2,l,m,u,v,val);
	}
	if (res==-1){
		res = get(id*2+1,m+1,r,u,v,val);
	}
	return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    file("1");
    cin >> n >> q;
    memset(t,oo,sizeof t);
    f1(i,1,n) cin >> a[i],upd(1,1,n,i,a[i]);
    while (q--){
    	cin >> k >> u >> v;
    	if (k==1) upd(1,1,n,u,v);
    	else {
    		cin >> val;
    		int ans = -1;
    		ans = get(1,1,n,u,v,val);
    		if (ans==-1) cout << "Skip\n"; else cout << ans << '\n';
    	}
    }
    return 0;
}

