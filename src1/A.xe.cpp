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
const int mod = 1e9+7;
const ll inf = 1e12;
 
using namespace std;
void solve()
{
	string str;
	cin >> str;
	unordered_map<int,char> mp;
	f1(i,1,8) mp[i] = char(i+96);
	char A = str[0];
	int B = str[1] - '0';
	int C = str[0] - '0'; C-=48;
	// cout << C << '\n';
	f1(i,1,8) if (C!=i) cout << mp[i] << str[1] << '\n';
	f1(i,1,8)
		 if (B!=i)cout << A << i << '\n';
	
	cout << '\n';
}
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("INP.INP","r",stdin);
    freopen("OUT.OUT","w",stdout);
    #endif // ONLINE_JUDGE
    faster;
    twt solve();
    return (0^0);
}