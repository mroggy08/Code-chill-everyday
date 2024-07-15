#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back

using namespace std;

const int maxn=3000000,mo=123456789;
// unordered_map <ll,ll> mp;
int f[maxn];
int n;
unordered_map <int,int> mp;
ll kq = 1;
void sang()
{
    for (int i = 2; i <= maxn; i++) f[i] = i;
    for (int i = 2; i <= maxn; i++)
    {
        if (f[i]==i)
        {
            for (int j = 2*i; j <= maxn; j+=i) if (f[j]==j) f[j] = i;
        }
    }
}
void ptich(int x)
{
    while (x>1)
    {
        ll u = f[x];
        mp[x]++;    
        if (u!=x)
        {
            mp[u] += mp[x];
            mp[x/f[x]] += mp[x];
            mp[x] = 0;
        }
        x/=u;
    }
}
bool so(ll n)
{
    string s = to_string(n);
    return s[s.size()-1] != '4';
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("INP.INP","r",stdin);
    freopen("OUT.OUT","w",stdout);
    #endif // ONLINE_JUDGE
    sang();
    cin >> n;
    for (ll i = 2; i <= n; i++)
        if (so(i)) ptich(i);
    for (int i = n; i >= 2; i--)
        kq = (kq*(mp[i]+1)*1LL)%mo;
    cout << kq;
    return 0;
}

