#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,sse4,avx,avx2,fma,bmi,bmi2,abm")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lb;
void fan_manchesterunited_20nam() {ios_base::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);}
void times() {cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";}
#define TrThanhDat int main()
ll gcd(ll a, ll b) {return __gcd(a,b);}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}
const ll mod = 1e9+7;
const int N = 2e5+3;
int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
char duong[] = {'R', 'L', 'D', 'U'};
#define ii pair<int,int>
#define fi first
#define se second
#define f1(i,n,m) for(int i=n;i<=m;i++)
#define f2(i,n,m,j) for (int i=n;i>=m;i-=j)
int n,m,tv[1003][1003];
char a[1003][1003];
queue <ii> q;
ii bd;
TrThanhDat {
	fan_manchesterunited_20nam;
	#define name "task"
	if(fopen(name".inp","r")){freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
	cin >> n >> m;
	f1(i,1,n) {
		f1(j,1,m){
			cin >> a[i][j];
			if (a[i][j]=='A'){
				bd = {i,j};
			} else
			if (a[i][j]=='M'){
				q.push({i,j});
			}
		}
	}
	q.push(bd);
//	cout << "a\n";
	while (q.size())
	{
	    ii cur = q.front();
		int u = q.front().fi, v = q.front().se;
		q.pop();
//		cout << u << ' ' << v << '\n';

		if (a[u][v]=='A' && (u==1||u==n||v==1||v==m))
		{
			cout << "YES\n";
			vector<int> kq;
			while(cur != bd)
			{
				int it = tv[cur.fi][cur.se];
				kq.push_back(it);
				cur = {cur.fi-dx[it],cur.se-dy[it]};
			}
			reverse(kq.begin(),kq.end());
			cout << kq.size() << '\n';
			for (int x : kq) cout << duong[x];
            return 0;
		}

		for (int k = 0; k < 4; k++)
		{
			int i2 = dx[k]+u, j2 = dy[k]+v;
			if (a[i2][j2]=='.'&&i2>0&&j2>0&&i2<=n&&j2<=m)
			{
//			    cout << i2 << ' ' << j2 << '\n';
				a[i2][j2] = a[u][v];
				if (a[i2][j2]=='A') tv[i2][j2] = k;
				q.push({i2,j2});
			}
        }
//            for(int i = 0; i < 4; i++) {
//                pair<int,int> nw = {cur.fi+dx[i], cur.se+dy[i]};
//                    if(a[nw.fi][nw.se] == '.' && 1 <= nw.fi && nw.fi <= n && 1 <= nw.se && nw.se <= m) {
//                        a[nw.fi][nw.se] = a[cur.fi][cur.se];
//                        if (a[nw.fi][nw.se] == 'A') tv[nw.fi][nw.se] = i;
//                            q.push(nw);
//                }
//            }
        }
    cout << "NO";
	times();
	return (0 ^ 0);
}
