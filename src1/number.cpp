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
int n,k,x,t,d[N],ma,kq;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//    freopen("task.inp","r",stdin);
//    freopen("task.out","w",stdout);
    cin >> n >> k;
    f1(i,1,n)
    {
        cin >> x;
        t = x%k;
        d[t]++;
    }
    for (int v = 1; v < k/2+k%2; v++)
        kq += max(d[k-v],d[v]);
    cout << kq;
    return 0;
}

