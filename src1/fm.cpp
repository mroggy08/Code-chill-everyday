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
int n,m,a[maxn+3],kq;
__ThanhDat()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define task "inp"
    if (fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> m;
    f1(i,1,n) cin >> a[i];
    sort(a+1,a+n+1);
    f1(i,1,n)
    {
        int vt = upper_bound(a+1,a+n+1,m-a[i]) - a - 1;
        // if (a[vt+1]+a[i]>m)
            kq += vt;
    }
    cout << kq;
    cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return (0 ^ 0);
}
