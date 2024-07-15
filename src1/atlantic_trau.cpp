#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N = 1e6+5;
const ll inf = 1e18;
const int mo = 1e9+7;
string n;
ll m,lt[N];
map<int,ll> mp;
ll chuyen(string n)
{
    ll tr = 0;
    for (auto x : n) tr = tr*10 + (x-'0');
    return tr;
}
void xuli(int n)
{
    string s1 = to_string(n);
    for (auto x : s1)
        mp[x-'0']++;
}
//bool ch(int n)
//{
//    string s2 = to_string(n);
//    if (s2[0]=='1') return 0l;
//    return 0;
//}
void sub1()
{
    for (int i = 1; i <= m; i++)
         xuli(i);
//        cout << '\n';
    for (int i = 0; i < 10; i++) cout << i << ' ' << mp[i] << '\n';
//    cout << mp[1];
}
//void sub2()
//{
//    lt[1] = 1;
//    for (int i = 2; i <= 1000; i++)
//        lt[i] = lt[i-1]*10;
//
//}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    freopen("task.INP","r",stdin);
    freopen("task.OUT","w",stdout);
    cin >> n;
    m = chuyen(n);
    sub1();
    return 0;
}

