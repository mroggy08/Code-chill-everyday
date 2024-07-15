#include <bits/stdc++.h>

using namespace std;
long long n,q,u,v,a[20003],t[20003][16];
void build()
{
    for (long long i = 1; i <= n; i++) t[i][0] = a[i];
    for (long long k = 1; k <= 16; k++)
    {
        for (long long i = 1; i + (1<<k)-1<= n; i++)
            t[i][k] = min(t[i][k-1],t[i+(1<<(k-1))][k-1]);
    }
}
long long get(long long l, long long r)
{
    long long k = __lg(r-l+1);
    return min(t[l][k],t[r-(1<<k)+1][k]);
}
int main()
{
    cin >> n >> q;
    for (long long i = 1; i <= n; i++) cin >> a[i];
    build();
    while (q--)
    {
        cin >> u >> v;
        cout << get(u,v) << '\n';
    }
    return 0;
}
