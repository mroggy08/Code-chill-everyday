#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define Vii vector<ii>
#define X first
#define Y second
#define pri priority_queue <ii,Vii, greater<ii>>
#define pb push_back
#define f1(i,n,m) for (int i=(n);i<=(m);++i)
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;

const int N = 1e6+3;
const int M = 2e3+3;
const int mod = 1e9+7;

string s,s1;
int dp[M][M];
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("INP.INP","r",stdin);
//    freopen("OUT.OUT","w",stdout);
    #endif // ONLINE_JUDGE
    fastIO;
    cin >> s;
    s1 = s;
    reverse(s1.begin(),s1.end());
    s = " " + s; s1 = "#" + s1;
    int n = s.size(), m = s1.size();
    f1(i,1,n) f1(j,1,m)
    {
        if (s[i] == s1[j]) dp[i][j] = dp[i-1][j-1] + 1;
        else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
    }string kq,ans;
    while (n>0 && m>0)
    {
        if (s[n]==s1[m]) kq += s[n],n--,m--;
        else if (dp[n-1][m] > dp[n][m-1]) n--;
        else m--;
    }
    for (int i = 1; i < kq.size(); i++) ans+=kq[i];
//    for (int i =)
    cout << ans;
//    cout << dp[n][m];
    return (0^0);
}
