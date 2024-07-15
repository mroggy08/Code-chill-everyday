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
ll n,a[500003],l,r,k;
ll kq;
unordered_map<int,int> mp; 
__ThanhDat()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define task "inp"
    if (fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n;
    f1(i,1,n) cin >> a[i],mp[a[i]]++;
    sort(a+1,a+n+1);
    f1(i,1,n)
    {
        if (mp[a[i]]>1)
        {
            l = upper_bound(a+1,a+n+1,0) - a;
            r = lower_bound(a+1,a+n+1,2*a[i]) - a;
            k = (r - l) - mp[a[i]];
            kq += k*(mp[a[i]]*(mp[a[i]]-1)/2);
            if (mp[a[i]]>=3) kq +=  ( p[a[i]]*(mp[a[i]]-1)*(mp[a[i]]-2) )/6;
            mp[a[i]] = 0;
        }
    }
    cout << kq;
    cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return (0 ^ 0);
}