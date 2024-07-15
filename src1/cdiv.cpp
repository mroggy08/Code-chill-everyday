#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back

using namespace std;

const int N = 1000003,mo = 123456789,maxn=3000000;
int n,x;
ll f[maxn+3];
ll kq = 1;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    sang();
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if (x>1) ptich(x);
    }
    for (auto it : mp)
      kq = (kq*1LL*(it.se+1))%mo;
    cout << kq;
    return 0;
}
