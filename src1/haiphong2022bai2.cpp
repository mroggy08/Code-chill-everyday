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
const int M = 1e3+3;
const int mod = 1e9+7;

bool cmd(string a, string b)
{
    return a+b>b+a;
}
int n;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("INP.INP","r",stdin);
    freopen("OUT.OUT","w",stdout);
    #endif // ONLINE_JUDGE
    fastIO;
    cin >> n;
    vector<string> a(n);
    for (auto &t : a)cin >> t;
    sort(a.begin(),a.end(),cmd);
    for (auto t : a) cout << t;
    return (0^0);
}
