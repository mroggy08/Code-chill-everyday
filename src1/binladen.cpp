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
const int inf = 1e9;
int m,n,w,d[N];
vii a[N];
void dis()
{
    priority_queue<ii,vii,greater<ii>> q;
    f1(i,1,(m+1)*n) d[i]=1e9;
    d[(m+1)*n]=0;
    q.push({0,m*n+n});
    while (q.size())
    {
        int du = q.top().fi,u = q.top().se;
//        cout << u << ' ' << du << '\n';
        q.pop();
        if (du > d[u]) continue;
        for (auto it : a[u])
        {
            int dv = it.fi,v = it.se;
//            cout << dv << "a ";
//            cout << d[v] << ' ' << du << ' ' << dv << '\n';
            if (d[v] > dv + du)
            {
                d[v] = dv + du;
                q.push({d[v],v});
            }
        }
    }
    int kq = 1e9;
    f1(i,1,n) kq = min(kq,d[i]);
    cout << kq;
//    cout << '\n';
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//    freopen("task.inp","r",stdin);
//    freopen("task.out","w",stdout);
    cin >> m >> n;
//    for (int i = 2; i <= n; i++)
//    {
//        a[i].pb({1,i-1});
//        a[i-1].pb({1,i});
//    }
    f1(i,1,m)
    {
//        if (i%2==0)
//        {
            f1(j,1,n)
            {
                cin >> w;
                a[(i-1)*n + j].pb({w,i*n+j});
                a[i*n + j].pb({w,(i-1)*n+j});
//                cout << (i-1)*n + j << ' ' << (i-1)*n+j-n << '\n';
            }
//        }
//        else {
            f1(j,1,n-1)
            {
                cin >> w;
               a[i * n + j].push_back({w,i * n + j + 1});
                a[i * n + j + 1].push_back({w,i * n + j});
//                cout << (i-1)*n + j << ' ' << (i-1)*n+j+1 << '\n';
            }
//        }
    }
//    cout << d[1] << ' ' << d[2] << ' ' << d[3] <<  ' ';
//    cout << d[n*m+n];
    dis();
//    cout << d[n*m+n] << ' ';
//    dis(2);
//    cout << d[n*m+n] << '\n';
//    for (int i = 1; i <= n*m + n; i++)
//    {
//        for (auto it : a[i])
//            cout << i << ' ' << it.fi << ' ' << it.se << '\n';
//        cout << '\n';
//    }
    return 0;
}
