#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define ii pair<int,int>
#define vi vector<int> 
#define vii vector<ii>
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
#define __ThanhDat int main

//            ______________Code_______________

using namespace std;

const int maxd = 1e3;
const int maxn = maxd*maxd;
const ll mo = 1000000007;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

//             ______________Start_______________

string S = "1000000000";
ll n;
string m;
bool sosanh(string a, string b)
{
    if (a.size()<b.size()) return 1;
    if (a.size()>b.size()) return 0;
    return a<=b;
}
ll lt1(ll a, ll b)
{
    if (b==0) return 1;
    if (b==1) return a;
    ll s = lt1(a,b/2);
    s = (s*s)%mo;
    if (b&1) s = (s*a)%mo;
    return s;
}
ll change(string x)
{
    ll ans = 0;
    for (auto s : x) ans = ans*10 + s-'0';
    return ans; 
}
__ThanhDat()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define task "inp"
    if (fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> m;
    if (n<=1e9 && sosanh(m,S))
    {
        ll M = change(m);
        ll kq = lt1(n,M);
        cout << kq;
    }
    else 
    {
        string s2 = "";
        for (int i = 0; i < 8; i++)
            s2 += m[i];
        ll M = change(s2);
        ll kq = lt1(n,M);
        for (int i = 8; i < m.size(); i++)
            kq = (lt1(kq,10)*lt1(n,m[i]-'0'))%mo;
        cout << kq;        
    }
    cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return (0 ^ 0);
}