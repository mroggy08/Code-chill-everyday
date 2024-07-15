#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define Vii vector<ii>
#define fi first
#define se second
#define pri priority_queue <ii,Vii, greater<ii>>
#define pb push_back
#define FOR(i,n) for (int i = 1; i <= (n); i++)
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define twt int T;cin>>T;while(T--)

using namespace std;

const int N = 1e6+3;
const int M = 1e3+3;
const int mod = 1e9+7;
const int inf = 1e9;
int n,m;
struct edge
{
	int u,v,w,ok;
};
edge a[1003];
int dis[103],cha[103];
int vis[103];
int kc[103][103];
int kq = INT_MAX;
bool cmd(edge X, edge Y)
{
	return X.w < Y.w;
}
int find(int v)
{
	if (v==cha[v]) return v;
	return cha[v] = find(cha[v]);
}
void kruskal()
{
	int cnt = 0;
	FOR(i,m)
	{
		if (cnt==n-1) break;
		int uu = a[i].u, vv = a[i].v, ww = a[i].w;
		int r1 = find(uu), r2 = find(vv);
		if (r1!=r2)
		{
			a[i].ok = 1;
			cha[r2] = r1;
			kc[uu][vv] = kc[vv][uu] = ww;
			cnt++;
		}
	}
}
void dfs(int u, int p)
{
	vis[u] =1;
	if (u==p) return;
	FOR(i,n)
	{

		if (kc[u][i] > 0 && vis[i]==0)
		{
			dis[i] = dis[u] + kc[u][i];
			dfs(i,p);
		}
	}
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("INP.INP","r",stdin);
    freopen("OUT.OUT","w",stdout);
    #endif // ONLINE_JUDGE
    faster;
    cin >> n >> m;
    FOR(i,m){
    	cin >> a[i].u >> a[i].v >> a[i].w;
    	a[i].ok = 0;
    }
    sort(a+1,a+m+1,cmd);
    FOR(i,n) cha[i] = i;
    kruskal();
    FOR(i,m)
    {
    	if (a[i].ok==0)
    	{
    		int uu = a[i].u, vv = a[i].v, ww = a[i].w;
    		memset(vis,0,sizeof vis);
    		memset(dis,0,sizeof dis);
    		dfs(uu,vv);
    		// cout << uu << ' ' << vv << '\n';
    		// cout << dis[vv] << '\n';
    		// cout << kq << '\n';
    		if (vis[vv]==1)
    		{
    			kq = min(kq,dis[vv] + ww);
    		}
    	}
    }
    cout << (kq==INT_MAX ? 0 : kq);
    return (0^0);
}