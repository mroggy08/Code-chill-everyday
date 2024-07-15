#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define __ThanhDat int main
using namespace std;
const int N = 1e4+3;
const ll mo = 1000000007;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int a,b;
__ThanhDat()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    #define task "inp"
    if (fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> a >> b;
    cout << a + b;
    return 0;
}
