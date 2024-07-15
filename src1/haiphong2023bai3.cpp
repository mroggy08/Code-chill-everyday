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
int n,x,q,u,v;
ll s[M];
bool nt(ll n)
{
    for (int i = 2; i*i <= n; i++)
        if (n%i==0) return 0;
    return n>1;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("INP.INP","r",stdin);
    freopen("OUT.OUT","w",stdout);
    #endif // ONLINE_JUDGE
    fastIO;
    cin >> n >> q;
    f1(i,1,n) {
        cin >> x, s[i] = s[i-1] + x;
    }
    while (q--)
    {
        cin >> u >> v;
        cout << (nt(s[v]-s[u-1]) ? 1 : 0) << '\n';
    }
    return (0^0);
}
