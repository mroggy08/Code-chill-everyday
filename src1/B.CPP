#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 2e6+5;
int n,f[maxn],d;
void sang(int n)
{
    f[0] = f[1] = 1;
    for (int i = 2; i*i <= n; i++)
    {
        if (!f[i])
        {
            for (int j = i*i; j <= n; j+=i) f[j] = 1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("INP.INP","r",stdin);
    freopen("OUT.OUT","w",stdout);
    #endif // ONLINE_JUDGE
    int n;
    cin >> n;
    sang(2*n);
    for (int i = n+1; i < 2*n; i++)
    {
        if (!f[i]) cout << i << ' ',d++;
    }
    cout << '\n' << d;

    return 0;
}