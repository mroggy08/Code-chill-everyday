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
const int N = 1e6+3;
int tc;
ll a,b,u,v;
double k;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//    freopen("div.inp","r",stdin);
//    freopen("div.out","w",stdout);
    cin >> tc;
    while (tc--)
    {
        cin >> a >> b;
        if (!b)
            cout << "0 0\n";
        else if (!a)
            cout << "0 1\n";
        else {
            k = 1.0*a/b;
//            cout << k << '\n';
            if (k==-1)
                cout << "0 0\n";

            else {
                u = a/__gcd(a,b);
                v = b/__gcd(a,b);
//                cout << __gcd(a,b) << '\n';
                if (u < 0 || v < 0){
                    if (abs(u)>abs(v)) cout << abs(u) << ' ' << -abs(v) << '\n';
                    else cout << -abs(u) << ' ' << abs(v) << '\n';
                }
                else cout << u << ' ' << v << '\n';

            }
        }
    }
    return 0;
}

