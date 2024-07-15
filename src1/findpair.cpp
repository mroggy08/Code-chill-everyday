#include <bits/stdc++.h>
#define vi vector<int>
#define vii vector<ii>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)

using namespace std;

const int N = 1e6+3;
const ll inf = 1e18;
const int mo = 1e9+7;
const int dx[4]{1,-1,0,0},dy[4]{0,0,1,-1};
string n,s;
ll m;
int tong(string s)
{
    int k = 0;
    for (char x : s) k += (x-'0');
    return k;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define task "task"
    if (fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n;
    m = tong(n);
//    cout << m << '\n';
    while (m>9)
    {
        s = to_string(m);
        m = tong(s);
//        cout << m << ' ';
    }
    cout << m;
    return 0;
}
