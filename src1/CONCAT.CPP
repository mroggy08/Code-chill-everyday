#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pi2 pair<pii,int>
#define vii vector<pii>
#define vi2 vector<pi2>
#define fi first
#define se second
#define pri priority_queue <pii,vii, greater<pii>>
#define pb push_back
#define f1(i, l, r) for (int i = l; i <= r; ++i)
#define f2(i, l, r) for (int i = l; i >= r; --i)
#define f3(i, l, r) for (int i = l; i < r; i++)
#define lb lower_bound
#define ub upper_bound
#define cinarr(a) for (int i = 1; i<=n; ++i) cin >> a[i];
#define cinvec(a) for (auto &x : a) cin >> x;
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define twt int T;cin>>T;while(T--)
 
const int N = 1e6+3;
const int M = 1e3+3;
const ll md = 1e9+7;
const ll inf = 1e12;
int base = 31;
using namespace std;

int lenA,lenB;
string a,b;
ll lt[N],hashA[N],hashB;
ll gethash(int i, int j)
{
    return (hashA[j] - hashA[i-1]*lt[j-i+1] + md*md)%md;
}
int main()
{
    faster;
    lt[0]=1;
    for (int i = 1; i <= 1e6; i++)
        lt[i] = (lt[i-1]*base)%md;
    int tt; cin >> tt; while (tt--)
    {
    	vector <int> vt;
    	vt.clear();
    	cin >> a >> b;
    	// cout << a << ' ' << b << '\n';
    	lenA = a.size(); lenB = b.size();
    	a = " " + a;
    	b = " " + b;
    	f1(i,1,lenA) hashA[i] = 0; 
    	hashB = 0;
    	f1(i,1,lenA)
        hashA[i] = (hashA[i-1]*base + (a[i]-'0'))%md;
    	f1(i,1,lenB)
      	  hashB = (hashB*base + (b[i]-'0'))%md;
    	f1(i,1,lenA-lenB+1)
       	 	if (hashB == gethash(i,i+lenB-1))
            	vt.pb(i);
           if (vt.size()==0) 
           {
           	cout << -1 << '\n';
           	continue;
           }
          cout << vt.size() << '\n';
          for (auto it : vt )cout << it << ' ';
        cout << '\n';
    }
    return 0;
}
 