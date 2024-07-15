#include <bits/stdc++.h>
#define N 100000
#define ll long long
#define pii pair<int,int>
using namespace std;
pii a[N+3];
ll sumw[N+3];
int n,X,k;
ll kq;
int tk(int X)
{
    for (int i = 1; i <= n; i++)
        if (a[i].first == X) return i;
    return 0;
}
int main()
{
    cin >> n >> X >> k;
    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    if (tk(X)==0)
    {
        n++;
        a[n] = {X,0};
    }
    sort(a+1,a+n+1);
    for (int i = 1; i <= n; i++)
        sumw[i] = sumw[i-1] + a[i].second;
    int pos = tk(X);
    int p = lower_bound(a+1,a+n+1,pii(a[pos].first -k,0)) - a;
    for (int i = p; i <= pos; i++)
    {
        ll dis = a[pos].first - a[i].first;
        int j = upper_bound(a+1,a+n+1,pii(a[i].first + (k-dis),N)) - a - 1;
        ll w = sumw[j] - sumw[i-1];
        kq = max(kq,w);
    }
    p = upper_bound(a+1,a+n+1,pii(a[pos].first + k,0)) - a - 1;
    for (int i = pos; i <= p; i++)
    {
        ll dis = a[i].first - a[pos].first;
        int j = lower_bound(a+1,a+n+1,pii(a[i].first - (k - dis),N)) - a;
        ll w = sumw[i] - sumw[j-1];
        kq = max(kq,w);
    }
    cout << kq;
    return 0;
}
