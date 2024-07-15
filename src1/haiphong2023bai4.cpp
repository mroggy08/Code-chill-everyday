#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define Vii vector<ii>
#define X first
#define Y second
#define pri priority_queue <ii,Vii, greater<ii>>
#define pb push_back
#define f1(i,n,m) for (int i=(n);i<=(m);++i)
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;

const int N = 1e6+3;
const int M = 1e3+3;
const int mod = 1e9+7;

int n,k;
int a[N];
int d,r,l;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("INP.INP","r",stdin);
    freopen("OUT.OUT","w",stdout);
    #endif // ONLINE_JUDGE
    fastIO;
    int tt; cin >> tt;
    while (tt--)
    {
        d = 0;
        cin >> n >> k;
        f1(i,1,n) cin >> a[i];
        if (k%2==0)
        {
            cout << 0;
            continue;
        }
        sort(a+1,a+n+1);
        for (int i = 1; i <= n; i++)
        {
            if (a[i]> k/2) break;
            l = lower_bound(a+1,a+n+1,k-a[i]) - a;
            r = upper_bound(a+1,a+n+1,k-a[i]) - a;
            if (a[l]==k-a[i])
            {
//                cout << k-a[i] << '\n';
            if ((a[i]%2==0&&a[l]%2!=0)||(a[i]%2!=0&&a[l]%2==0)) d+=r-l;
            }
        }
        cout << (d!=0 ? 1 : 0);
    }
    return (0^0);
}
