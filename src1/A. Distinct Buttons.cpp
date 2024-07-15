#pragma GCC optimize("02")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define vii vector<pii>
#define pri pri priority_queue <pii,vii, greater<pii>>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FOD(i, a, b) for (int i = (a); i >= (b); i--)
#define REP(i, a) for (int i = 0; i < (a); i++)
#define ALL(x) (x).begin(), (x).end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

using namespace std;

const int MAXN = 1e5+5;
int tc,n;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("INP.INP","r",stdin);
    freopen("OUT.OUT","w",stdout);
    #endif // ONLINE_JUDGE
    cin >> tc;
 	while (tc--)
 	{
 		int a,b,c,d; a=b=c=d=0;
 		cin >> n;
 		FOR(i,1,n) {
 			int x,y;
 			cin >> x >> y;
 			if (x>0) a=1;
 			else if (x<0) b=1;
 			if (y>0) c=1;
 			else if (y<0) d=1;
 		}
 		cout << (a+b+c+d==4 ? "NO\n" : "YES\n");
 	}
    cerr << "Time elapsed: " << TIME << " s.\n"; 
    return (0^0);
}