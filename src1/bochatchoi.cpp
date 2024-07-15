#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define xi first
#define hi second
#define vi vector<int>
#define vii vector<ii>
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
#define bit(i,x) ((x>>i)&1)
#define bp __builtin_popcount
using namespace std;
const int N = 1e6+3;
int n,d,ma,t[N*4],kq;
ii a[N],g[N];
void build(int id, int l, int r)
{
    if (l==r)
    {
        t[id]=a[l].hi;
        return;
    }
    int m =(r+l)>>1;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    t[id]=max(t[id*2],t[id*2+1]);
}
int get(int id, int l, int r, int u, int v)
{
    if (u>r||v<l) return -1e9;
    if (u<=l&&v>=r) return t[id];
    int m = (r+l)>>1;
    return max(get(id*2,l,m,u,v),get(id*2+1,m+1,r,u,v));
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//    freopen("task.inp","r",stdin);
//    freopen("task.out","w",stdout);
    cin >> n >> d;
    f1(i,1,n) cin >> a[i].xi >> a[i].hi;
    build(1,1,n);
    sort(a+1,a+n+1);
    deque <int> dq;
    for (int i = 1; i <= n; i++)
    {
        while (dq.size() && a[i].xi - a[dq.front()].xi > d) dq.pop_front();
        if (dq.size())
        {
              ma = get(1,1,n,dq.front(),dq.back());
//        cout << dq.front() << ' ' << dq.back() << '\n';
            if (ma >= 2*a[i].hi) g[i].xi = 1;
//        cout << ma << ' ';
        }
        else {
            g[i].xi = 0;
        }
//        ma = get(1,1,n,dq.front(),dq.back());
//        cout << dq.front() << ' ' << dq.back() << '\n';
//        cout << ma << ' ';
        dq.push_back(i);
    }
    dq.clear();
    for (int i = n; i > 0; i--)
    {

        while (dq.size() && abs(a[i].xi - a[dq.front()].xi) > d) dq.pop_front();
        if (dq.size())
        {
              ma = get(1,1,n,dq.front(),dq.back());
//        cout << dq.front() << ' ' << dq.back() << '\n';
            if (ma >= 2*a[i].hi) g[i].hi = 1;
//        cout << ma << ' ';
        }
        else {
            g[i].hi = 0;
        }
        dq.push_back(i);
    }
    for (int i = 1; i <= n; i++) if (g[i].hi || g[i].xi) kq++;
    cout << kq;
    return 0;
}

