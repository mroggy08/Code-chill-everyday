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

const int N = 1e5+3;
const int M = 1e3+3;
const int mod = 1e9+7;

int n,k;
int p1=-1,p2,l;
ii a[N];
int tknp(int l, int r, int digit)
{
    int kq=-1;
    while (l<=r)
    {
        int m = (r+l)/2;
        if (a[m].X==digit)
        {
            kq = m;
            r = m-1;
        }
        else l = m + 1;
    }
    return kq;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("INP.INP","r",stdin);
    // freopen("OUT.OUT","w",stdout);
    #endif // ONLINE_JUDGE
    fastIO;
    cin >> n >> k;
    f1(i,1,n) cin >> a[i].X, a[i].Y = i;
    sort(a+1,a+n+1);
    vector <ii> kq;
    f1(i,1,n)
    {
//        cout << k*2 - a[i].X << ' ';
        l = tknp(i,n,k*2-a[i].X);
//        cout << l << '\n';
        if (l!=-1)
        {
            kq.pb({a[i].Y,a[l].Y});
        }
    }
    if (kq.size())
    {
        sort(kq.begin(),kq.end());
        // for (auto it : kq) cout << it.X << ' ' << it.Y << '\n';
        cout << kq[0].X << ' ' << kq[0].Y;
    }
    else cout << "0 0";
    return (0^0);
}
