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
const ll mod = 1e9+7;
int base = 31;
ll lt[N],B,A[N],kq;
ll get(int u, int v)
{
    return (A[v] - A[u-1]*lt[v-u+1] + mod*mod)%mod;
}
string s,s1;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("INP.INP","r",stdin);
    freopen("OUT.OUT","w",stdout);
    #endif // ONLINE_JUDGE
    fastIO;
    cin >> s;
    int n = s.size();
    s1 = "virus";
    s = " " + s;
    lt[0]=1;
    f1(i,1,n) lt[i] = (lt[i-1]*base)%mod;
    f1(i,1,5) B = (B*base + s1[i-1])%mod;
    f1(i,1,n) A[i] = (A[i-1]*base + s[i])%mod;
    for (int i = 1; i <= n-4; i++)
        if (B==get(i,i+4)) kq++;
        cout << kq;
    return (0^0);
}
