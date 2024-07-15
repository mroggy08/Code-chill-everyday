#include <bits/stdc++.h>
using namespace std;
#define fi first 
#define se second
#define pb push_back
#define ll long long 
#define l2 pair<ll,ll>
#define vi vector<int>
#define vi2 vector<ii>
#define vil vector<il>
#define vl2 vector<l2>
#define lb lower_bound
#define ub upper_bound
#define li pair<ll,int>
#define il pair<int,ll>
#define vli vector<lli>
#define i2 pair<int,int>
#define ALL(a) a.begin(),a.end()
#define fd(i,n) for (int i = n; i > 0; i--)
#define f1(i,n,m) for (int i = n; i <= m; i++)
#define file(name) if(fopen(name".inp","r")){freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
const int N = 2e5+5;
string a,b;
int dp[5005][5005],n,m;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    file("1");
    cin >> a >> b;
    n = a.size(); m = b.size();
    f1(i,1,m) dp[0][i] = i;
    f1(i,1,n) dp[i][0] = i;
    f1(i,1,n){
        f1(j,1,m){
            int cs = (a[i-1]!=b[j-1]);
            // cout << cs << ' ';
            dp[i][j] = min({dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+cs});
        }
    }
    cout << dp[n][m];
    return 0;
}
