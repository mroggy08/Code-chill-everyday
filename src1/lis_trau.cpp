#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+3;
int n,a[N],g[N],d[N],kq,f[N],id=1,h[1000003];
void sang()
{
    for (int i = 2; i <= 1000000; i++)
    {
        if (h[i]==0)
        {
            for (int j = i; j <= 1000000; j+=i)
                h[j] = i;
        }
    }
}
int pt1(int x){
    int m = x, so = 1,tam,dem;
    while (m>1)
    {
        dem = 0;
        tam = h[m];
        while (m%tam==0) m/=tam, dem++;
        so *= (dem+1);
    }
    return so;
}
bool cp(int t)
{
    int tam = sqrt(t);
    return tam*tam ==t;
}
int pt(int x)
{
    int dem = 0;
    for (int k1 = 1; k1 <= sqrt(x); k1++)
    {
        if (x%k1==0)
            dem += 2;
    }
    if (cp(x)) dem-=1;
    return dem;
}
void sub1()
{
//      for (int i = 1; i <= n; i++)
//    {
//        for (int j = 0; j < i; j++)
//        {
//            if (g[i]>g[j]) f[i] = max(f[i],f[j]+1);
//        }
//    }
//    for (int i = 1; i <= n; i++) kq = max(kq,f[i]);
//    cout << kq;
     f[1] = g[1];
    for (int i = 2; i <= n; i++)
    {
        if (g[i] > f[id])
        {
            id++;
            f[id] = g[i];
        }
        else if (g[i] <= f[1]) f[1] = g[i];
        else
        {
            int u = 1, v = id, m;
            while (v>u+1)
            {
                m = (u+v)>>1;
                if (g[i]>f[m]) u = m;
                else v = m;
            }
            f[v] = g[i];
        }
    }
    cout << id;
}
void sub2()
{
    for (int i = 1; i <= n; i++)
    {
//        d[i] = 1e9;
        int vt = lower_bound(d+1,d+kq+1,g[i]) - d;
        d[vt] = g[i];
        kq = max(kq,vt);
    }
    cout << kq;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("task.INP","r",stdin);
    freopen("task.ans","w",stdout);
    sang();
//    cout << pt(6) << ' ';
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] <= 1e6) g[i] = pt1(a[i]);
        else g[i] = pt(a[i]);
//        cout << g[i] << ' ';
    }
//    for (int i = 1; i <= n; i++)
//        pt(a[i]);
//    for (int i = 1; i <= n; i++) cout << g[i] << ' ';
    if (n<=1000) sub1();
//    sub1(); cout << '\n';
    else sub2();
    return 0;
}
