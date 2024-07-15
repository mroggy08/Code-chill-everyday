#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back

using namespace std;

const int N = 2e6+3;
ll n;
int f[N];
bool nt(ll n)
{
    for (ll i = 2; i <= sqrt(n); i++)
        if (n%i==0)
            return 0;
    return n > 1;
}
void sang()
{
    f[1] = f[0] = 1;
    for (int i = 2; i*i <= 2e6; i++)
    {
        if (!f[i])
        {
            for (int j = i*i; j <= 2e6; j+=i) f[j] = 1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    if (nt(n))
    {
        cout << n;
        return 0;
    }
    if (n<=1e6)
    {
        sang();
        while (1)
        {
            n++;
            if (f[n]==0)
            {
                cout << n;
                break;
            }
        }
    }
    else
    {
        while (1)
        {
            n++;
            if (nt(n))
            {
                cout << n;
                break;
            }
        }
    }
    return 0;
}

