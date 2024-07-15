#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define vi vector<int>
#define vii vector<ii>
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
#define bit(i,x) ((x>>i)&1)
#define bp __builtin_popcount
#define inf INT_MAX
using namespace std;
const int N = 1e6+3;
const long long M = 1e11;
int val,w,n,W;
ll s;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define task "task"
    if (fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    vector<long long> dp(100001, M);
    cin >> n >> W;
    dp[0] = 0;
    f1(i,1,n){
    	cin >> w >> val;
    	s+=val;
    	for (ll s1 = s; s1 >= val; s1--)
    		dp[s1] = min(dp[s1],dp[s1-val] + w);
    }
    for (ll v = s; v > 0; v--)
    	if (dp[v]<=W)
    	{
    		cout << v;
    		return 0;
    	}
    // {
    // 	cout << dp[v] << ' ';
    // }
    return 0;
}
