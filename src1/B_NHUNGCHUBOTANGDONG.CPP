#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define __ThanhDat int main
using namespace std;
const int N = 1e5+3;
const ll mo = 1000000007;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int n,k,a[N],t[N*4],l1,r1,g1;
void build(int id, int l, int r)
{
    if (l==r){
        t[id] = a[l];
        return;
    }
    int m = (r+l)>>1;
    build(id*2,l,m); build(id*2+1,m+1,r);
    t[id] = max(t[id*2],t[id*2+1]);
}
int get(int id, int l, int r, int u, int v)
{
    if (u>r||v<l) return -1e9;
    if (u<=l&&v>=r) return t[id];
    int m = (r+l)>>1;
    return max(get(id*2,l,m,u,v),get(id*2+1,m+1,r,u,v));
}
__ThanhDat()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    #define task "run"
    if (fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin>>a[i];
        build(1,1,n);
    for (int i = 1; i <= n; i++)
    {
        l1 = i; r1 = n;
         g1 = 0;
        while (r1>=l1)
        {
            int m1 = (l1+r1)>>1;
            if (get(1,1,n,l1,r1) <= a[i] + k) {
                g1 = m1;
                l1 = m1 + 1;
            }
            else r1 = m1 - 1;
        }
        cout << g1 << ' ';
    }
    cout << '\n';
    l1 = 3; r1 = n;
    while (r1>=l1)
    {
        int m1 = (l1+r1)>>1;
        if (get(1,1,n,l1,r1) <= a[3] + k){
            cout << get(1,1,n,l1,r1) << ' ';
            g1 = m1;
            l1 = m1+1;
            cout << m1 << '\n';
        }
        else {
            cout << get(1,1,n,l1,r1) << "a\n";
            r1 = m1-1;

        }
    }
    return 0;
}
