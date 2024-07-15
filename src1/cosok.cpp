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

ll n; int k;
int f[maxn];
int A[maxn],B[maxn],C[maxn];
ll tmp,kq=1e18;
unordered_map<int,int> mp;
bool nt(int n)
{
    for (int m = 2; m <= sqrt(n); m++)
        if (n%m==0) return 0;
    return n>1;
}
void pt(int x)
{
    int dem=0;
    for (int i = 1; i <= sqrt(x); i++)
        {
            if (x%i==0)
        {
            if (i*i!=x)
            {
                if (nt(i)) C[++dem] = i;
                if (nt(x/i)) C[++dem] = x/i;
            }
            else if (i*i==x)
            {
                if (nt(i)) C[++dem] = i;
            }
        }
        }
    for (int i = 1; i <= dem; i++)
    {
        while (x%C[i]==0)
        {
            mp[C[i]]++;
            x/=C[i];
        }
    }
}
ll tinh(ll n, int p)
{
    ll sum = 0;
    while (n>=p)
    {
        sum += n/p;
        n/=p;
    }
    return sum;
}
__ThanhDat()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define task "inp"
    if (fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> k;
    pt(k);
    int t = 0;
    for (auto it : mp)
        A[++t] = it.fi, B[t] = it.se;
    f1(i,1,t)
    {
        tmp = tinh(n,A[i]);
        kq = min(kq,tmp/B[i]);
    }
    cout << kq;
    cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return (0 ^ 0);
}
