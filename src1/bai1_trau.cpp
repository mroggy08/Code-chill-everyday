#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define vi vector<int>
#define vii vector<ii>
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
#define bit(i,x) ((x>>i)&1)
#define bp __builtin_popcount
using namespace std;
const int N = 1e6+3;
ll a,b;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("bai1.inp","r",stdin);
    freopen("bai1.ans","w",stdout);
    cin >> a >> b;
    cout << a+b;
    return 0;
}

