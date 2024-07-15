#include <bits/stdc++.h>
using namespace std;
int n,u,v,tt;
int x,f[1000003],pr[1000003];
void sang()
{
    pr[1] = pr[0] = 1;
    for (int i = 2; i*i <= 1e6; i++)
        if (!pr[i])
            for (int j = i*i; j <= 1e6; j+=i) pr[j] = 1;
}
bool bp(int n)
{
//    string tam = to_string(n);
    for (int k = 0; k <= 9; k++)
        if (pr[n*10+k]==0) return 1;
    return 0;
}
bool check(int n)
{
    if (bp(n)==0) return 0;
    if (n<10) return 0;
    while (n>1)
    {
        if (pr[n]==1) return 0;
        n/=10;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
//    freopen("INP.INP","r",stdin);
//    freopen("OUT.OUT","w",stdout);
    sang();
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if (pr[x]==1) f[i] = f[i-1];
        else if (pr[x]==0){
            if (check(x)) f[i] = f[i-1] + 1;
            else f[i] = f[i-1];
        }
    }
//    for (int i = 1; i <= n; i++)
//        cout << f[i] << ' ';
//    cout << '\n';
    cin >> tt;
    while (tt--)
    {
        cin >> u >> v;
        cout << f[v] - f[u-1] << '\n';
    }
    return 0;
}
