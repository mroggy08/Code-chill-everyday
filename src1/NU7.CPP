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
string b,a;
ll doi(string s)
{
    ll tam = 0;
    for (auto x : s) tam = tam*10 + (x-'0');
        return tam;
}
bool cp(ll m)
{
    ll k = sqrt(m);
    return k*k == m;
}
bool snt(ll n)
{
    for (ll i = 2; i <= sqrt(n); i++)
    {
        if (n%i==0) return 0;
    }
    return n > 1;
}
ll cb(ll n)
{
    ll l = 1, r = 2154435,kq;
    while (l<=r)
    {
        ll mid = (l+r)>>1;
        if (mid*mid*mid<=n) {
            kq = mid;
            l = mid + 1;
        }
        else r = mid-1;
    }
    return kq;
}
bool canba(ll u)
{
    ll k = cb(u);
    // cout << k << '\n';
    if (k*k*k != u) return 0;
    if (snt(k)) return 1;
        return 1;
}
bool check(string a)
{
    if (cp(doi(a)) || canba(doi(a))) return 1;
        return 0;
}
int f[M][M];
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("INP.INP","r",stdin);
    freopen("OUT.OUT","w",stdout);
    #endif // ONLINE_JUDGE
    fastIO;
    getline(cin,a);
    getline(cin,b);
    stringstream ss(a);
    stringstream sss(b);
    string t;
    vector <string> s1,s2;
    while (ss>>t)
    {
        if (check(t)) s1.pb(t);
    }
    while (sss>>t) if (check(t)) s2.pb(t);
    // cout << s1 << ' ' << s2 << '\n';
    int n = s1.size(), m = s2.size();
    // for (auto t : s1) cout << t << ' ';
    //     cout << '\n';
    // for (auto t : s2) cout << t << ' ';
    //     cout << '\n';
    f1(i,1,n) f1(j,1,m) {
        if (s1[i-1]==s2[j-1]) f[i][j] = f[i-1][j-1] + 1;
        else f[i][j] = max(f[i-1][j],f[i][j-1]);
    }
    cout << f[n][m];
    return (0^0);
}