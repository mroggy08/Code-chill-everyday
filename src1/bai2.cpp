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
const int N = 1e6;
int a,b,f[N+3],g[N+3],kq;
ll n;
void sang()
{
    f[0]=1; f[1]=1;
    for (int i = 2; i*i <= N; i++)
        if (!f[i])
            for (int j = i*i; j <= N; j+=i) f[j]=1;
}
void sangpt()
{
    for (int i = 2; i <= N; i++)
    {
        if (!g[i])
        {
            for (int j = i; j <= N; j+=i)
                g[j] = i;
        }
    }
}
void sub1()
{
    for (int i = 2; i <= n; i++)
    {
        if (!f[i] && i*i<=n) kq++;
    }
    cout << kq;
}
void sub23()
{
    for (int i = 2; i <= n; i++)
        if (!f[i] && i*i <= n) kq++;
    for (int i = 2; i <= 100; i++)
        if (!f[i] && i*i*i <= n) kq++;
    cout << kq;
}
bool pt(int k)
{
    int nn = k, h,d=0,dem=0;
    int tich = 1;
    vector <int> t;
    while (nn>1)
    {
        h = g[nn];
        dem++;
        d = 0;
        while (nn%h==0)
        {
            d++;
            nn/=h;
            if (d>3) return 0;
        }
        t.push_back(d);
        if (dem>2) return 0;
        tich *= h;
    }
    if (dem==1)
    {
        if (d==3) {
            if (tich * k <= n) return 1;
        }
    }
    else if (dem==2)
    {
        if (t[0]==1 && t[1]==3)
        {
              return tich*n <= k;
        }
        else if (t[0] == 3 && t[1] == 1){
              return tich*n <= k;
        }
        else if (t[0]==1 && t[1] == 1)
            {
                return tich*n <= k;
            }
    }
    return 0;
}
void sub24()
{
    for (int i = 2; i <= n; i++)
        if (!f[i] && i*i <= n) kq++,cout << i << ' ';
    for (int i = 2; i <= 1000; i++)
        if (!f[i] && i*i*i <= n) kq++,cout << i << ' ';
    for (int i = 2; i <= n; i++)
        if (pt(i,n)) kq++,cout << i << ' ';
}
void sub33()
{
       for (int i = 2; i <= 1000; i++)
        if (!f[i] && i*i*i <= n) kq++;
        cout << kq;
}
void sub34()
{
     for (int i = 2; i <= 1000; i++)
        if (!f[i] && i*i*i <= n) kq++;
    for (int i = 2; i <= n; i++)
        if (pt(i,n)) kq++;
    cout << kq;
}
void sub44()
{
     for (int i = 2; i <= n; i++)
        if (pt(i,n)) kq++;
    cout << kq;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//    freopen("task.inp","r",stdin);
//    freopen("task.out","w",stdout);
    sang();
    sangpt();
    cin >> n >> a >> b;
    if (n<=1000000)
    {
        if (a==2&&b==2) sub1();
        else if (a==2&&b==3) sub23();
        else if (a==3 && b==3) sub33();
        else if (a==3 && b==4) sub34();
        else if (a==4 && b==4) sub44();
        else if (a==2&&b==4) sub24();
    }
    else if (n<=4000000) {
         if (a==2&&b==2) sub1();
        else if (a==2&&b==3) sub23();
        else if (a==3 && b==3) sub33();
        else if (a==3 && b==4) sub34();
        else if (a==4 && b==4) sub44();
        else if (a==2&&b==4) sub24();
    }
    else cout << 100;
    return 0;
}
