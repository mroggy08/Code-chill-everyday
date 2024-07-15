#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N = 1e6+5;
const ll inf = 1e18;
const int mo = 1e9+7;
int n,h[N],f[N],l,r;
void sang()
{
     f[1]=f[0]=1;
    for (int i = 2; i*i <= 1000; i++)
    {
        if (!f[i])
        {
            for(int j = i*i; j <= 1000; j+=i) f[j]=1;
        }
    }
}
bool check(int n)
{
    int t = 0;
    while (n > 0){
        t += n % 10;
        n /= 10;
    }
    return f[t]==0;
}

void sub1()
{
    sang();
    for (int i = 1; i <= 1000000; i++)
    {
        if (check(i)) h[i] = h[i-1]+1;
        else h[i] = h[i-1];
    }
    cout << h[r] - h[l-1];
    cerr << "Time: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s.\n";
}
void sub2()
{
    sang();
    int kq = 0;
    for (int i = l; i <= r; i++)
    {
        if (check(i)) kq++;
    }
    cout << kq;
    cerr << "Time: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s.\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    freopen("task.inp","r",stdin);
    freopen("task.out","w",stdout);
    cin >> l >> r;
    if (r<=1000000) sub1();
    else sub2();
    return 0;
}

