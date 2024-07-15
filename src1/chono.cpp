#include <bits/stdc++.h>
#define fi first
#define se second
#define i2 pair <int, int>
#define il pair <int, long long>
#define li pair <long long, int>
#define ll long long
using namespace std;

const int N = 1e6 + 7, MOD = 1e9 + 7;
ll l,r,res,kq[N],f[N],l1,r1,t,g[N],Kq[N];

bool cp(ll n){
    ll k = sqrt(n);
    return k*k == n;
}
void sang1()
{
    for (int i = 2; i <= 1e6; i++)
    {
        if (g[i]==0)
        {
            for (int j = i; j <= 1e6; j+=i)
                g[j] = i;
        }
    }
}
bool ptts(int n)
{
    map <int,int> mp;
    int m = n;
    while (m>1){
        mp[g[m]]++;
        m/=g[m];
    }
    if (mp.size()>1) return 0;
    int tam;
    for (auto it : mp) tam = it.se + 1;
    return f[tam] == 0;
}
bool pt(int n){
    int nn = n,h,d=0,hh = 0;
    while (nn>1){
        h = g[nn];
        d++;
        if (d>1) return 0;
        while (nn%h==0) nn/=h, hh++;
    }
//    cout << hh << ' ' << n << '\n';
    hh = 2*hh+1;
    return f[hh]==0;
}
void sang()
{
    f[0] = 1; f[1] = 1;
    for (int i = 2; i*i <=  1e6; i++){
        if (!f[i]){
            for (int j = i*i; j <= 1e6; j+=i) f[j] = 1;
        }
    }
    for (int i = 2; i <= 1e6; i++) {
        if (!f[i]) kq[i] = kq[i-1] + 1;
        else if (cp(i) && ptts(i)) kq[i] = kq[i-1] + 1;
        else kq[i] = kq[i-1];
    }
    int l = 101,r = 1000000;
//    for (ll i = 1000001; i <= 1000000000000; i++)
//    {
//        if (cp(i) && )
//    }
    for (int i = l; i <= r; i++){
        if (pt(i)) Kq[i] = Kq[i-1]+1;
        else Kq[i] = Kq[i-1];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen("task.INP", "r"))
    {
        freopen("task.INP", "r", stdin);
        freopen("task.OUT", "w", stdout);
    }
    sang1();
    sang();
    int tc; cin >> tc;while (tc--)
    {
        res = 0;
        cin >> l >> r;
        if (l <= 1e6 && r <= 1e6)
        {
            cout << kq[r] - kq[l-1] << '\n';
        }
        else if (l > 1e6 && r > 1e6){
            l1 = sqrt(l);
            r1 = sqrt(r);
            if (l1*l1!=t) l1+=1;
//            res = kq[1000000];
            res = Kq[r1] - Kq[l1-1];
            cout << res << '\n';
        }
        else if (l <= 1e6 && r > 1e6){
            r1 = sqrt(r);
            res += (kq[1000000] - kq[l-1])+(Kq[r1] - Kq[100]);
            cout << res << '\n';
        }
//        else {
//            cout << Kq[r1] - Kq[l1 - 1]
//        }
    }
//    pt(4);
    //    cout << 1 << ' ';
    //f (pt())
    return 0;
}
